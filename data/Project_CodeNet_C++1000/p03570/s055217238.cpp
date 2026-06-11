#include<iostream>
#include<string>
#include<cstdio>
#include<vector>

using namespace std;

int main(void)
{
    string s;
    int h = 0;
    cin>>s;
    vector<int> dp(1<<26,1e9);

    dp[0] = 0;
    for(int i = 0;i < s.size();i++) {
       int bit = s[i] - 'a';
       h = h ^ (1<<bit);
       for(int j = 0;j < 26;j++) {
           dp[h] = min(dp[h],dp[h^(1<<j)]+1);
       }
    }

    cout<<max(1,dp[h])<<endl;

    return 0;
}
