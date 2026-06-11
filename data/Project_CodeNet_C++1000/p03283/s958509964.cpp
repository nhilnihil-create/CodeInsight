#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        dp[x][y]++;
    }
    for(int i=0;i<=n;i++)
         for(int j=1;j<=n;j++)
            dp[i][j]+=dp[i][j-1];

    for(int i=0;i<n;i++)
         for(int j=0;j<=n;j++)
            dp[i+1][j]+=dp[i][j];
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<dp[y][y]+dp[x-1][x-1]-dp[x-1][y]-dp[y][x-1]<<endl;
    }
}