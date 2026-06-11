#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int dp[n+5][n+5];
    int a[n+5];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=1e18;
    for(int i=0;i<n;i++)
        cin>>a[i],dp[i][i]=a[i];
    int sum[n+5][n+5];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            for(int k=i;k<=j;k++)
                sum[i][j]+=a[k];
    for(int i=1;i<n;i++)
        for(int j=0;j+i<n;j++)
            for(int k=j;k<i+j;k++)
            dp[j][i+j]=min(dp[j][i+j],dp[j][k] + dp[k+1][i+j] + sum[j][k] + sum[k+1][i+j]);
    cout<<dp[0][n-1]-sum[0][n-1];
}
