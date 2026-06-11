#include<bits/stdc++.h>
using namespace std;
int dp[1<<26];
int main()
{
    string s;
    cin>>s;
    int x=0;
    for(int i=0;i<(1<<26);i++)dp[i]=1e9;
    dp[0]=0;
    int ans=1e9;
    for(int i=0;i<s.size();i++)
	{
        ans=1e9;
        x^=1<<(s[i]-'a');
        ans=min(ans,dp[x]+1);
        for(int j=0;j<26;j++)ans=min(ans,dp[x^(1<<j)]+1);
        dp[x]=min(dp[x],ans);
    }
    cout<<ans<<endl;
    return 0;
}