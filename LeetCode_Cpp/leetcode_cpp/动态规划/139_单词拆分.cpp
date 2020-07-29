//
//  139_单词拆分.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/29.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        auto wordDictSet = unordered_set <string> ();
        for (auto word : wordDict) {
            wordDictSet.insert(word);
        }
        
        // dp[i] 表示 s 截止到第 i 位是否可拆分
        auto dp = vector<bool> (s.size() + 1);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
