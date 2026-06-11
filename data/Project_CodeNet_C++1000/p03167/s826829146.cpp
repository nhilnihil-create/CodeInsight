#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
signed main()
{
    SPEED;
    int n,m;
    cin>>n>>m;
    int a[n][m],dp[n][m];
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='#')
            a[i][j]=1;
        }
    }
    if(a[0][0]==0)
    dp[0][0]=1;
    for(int i=1;i<m;i++)
    {
        if(a[0][i]==0)
        dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i][0]==0)
        dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i][j]==0)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n-1][m-1];
}