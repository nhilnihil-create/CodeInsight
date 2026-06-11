#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long dp[1001][1001];
int main()
{
    long long n,m,i,j;
    char ch[1001][1001];
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) cin>>ch[i][j];
    dp[1][1]=1;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (ch[i][j]=='.') dp[i][j]+=dp[i-1][j]+dp[i][j-1],dp[i][j]%=mod;
    }
    cout<<dp[n][m]<<endl;
}
