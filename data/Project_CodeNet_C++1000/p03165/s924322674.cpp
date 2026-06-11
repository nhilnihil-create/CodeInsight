#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
//int count = 0;
vector<vector<int>> dp;
string solve(string s, string t)
{
    if(s=="" || t == "") return "";
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int row = dp.size() - 1;
    int col = t.length();
    string ans = "";

    // while(dp[row][col] == dp[row-1][col]){
    // //cout<<row<<" "<<col<<endl;
    //     row--;
    // }
    // cout<<row<<" "<<col;
    while (row >= 0 && col >= 0)
    {
//        if(col-1 >= 0) 
            //ans = s[col - 1] + ans;

        if (row - 1 >= 0 && col - 1 >= 0 && dp[row - 1][col - 1] != dp[row][col])
        {
            //int col = col;
            while(col - 1 >= 0 && dp[row][col] == dp[row][col-1]){
                col--;
            }
            while(row - 1 >= 0 && dp[row][col] == dp[row-1][col]){
                row--;
            }
       // cout<<col<<" ";
       if(col-1 >= 0)
            ans = t[col-1] + ans;
        }

            col--;
            row--;
        // row--;
        // col--;
    }
    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;
    if (s.length() < t.length())
    {
        dp = vector<vector<int>>(s.length() + 1, vector<int>(t.length() + 1, 0));
        cout << solve(s, t);
    }
    else
    {
        dp = vector<vector<int>>(t.length() + 1, vector<int>(s.length() + 1, 0));
        cout << solve(t, s);
    }
}