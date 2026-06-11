#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lli n,M=1000000007;
    cin>>n;
    lli i,j,dp[n+1][n+1],ans=0;
    memset(dp, 0LL, sizeof(dp));
    
    string s;
    cin>>s;
    
    dp[1][1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i-1;j++) dp[i-1][j]=(dp[i-1][j]+dp[i-1][j-1])%M;
        
        for(j=1;j<=i;j++)
        {
            if(s[i-2]=='<')
            {
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]%=M;
            }
            else
            {
                dp[i][j]+=dp[i-1][i-1];
                dp[i][j]-=dp[i-1][j-1];
                dp[i][j]+=M;
                dp[i][j]%=M;
            }
        }
    }
    
    for(i=1;i<=n;i++) ans+=dp[n][i];
    cout<<ans%M;
    return 0;
}