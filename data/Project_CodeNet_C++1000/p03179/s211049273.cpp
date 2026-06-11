#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        dp[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        dp[i-1][j]=(0LL+dp[i-1][j]+dp[i-1][j-1])%mod;
        for(int j=1;j<=i;j++)
        {
            if(str[i-2]=='<')
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=(0LL+dp[i-1][i-1]-dp[i-1][j-1]+mod)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    ans=(0LL+ans+dp[n][i])%mod;
    cout<<(ans+mod)%mod<<"\n";
    return 0;
}