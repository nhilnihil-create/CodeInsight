#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[401][401];
ll a[401];

void solve(ll n, ll m)
{
    if(dp[n][m]!=-1)
    {
        return;
    }
    dp[n][m]=LONG_LONG_MAX;
    
    ll sum=0;
    if(n==m)
    {
        dp[n][m]=0;
        return;
    }
    for(int i=n; i<=m; i++)
    {
        sum+=a[i];
    }
    
    for(int i=n; i<m; i++)
    {
        solve(n, i);
        solve(i+1, m);
        dp[n][m]=min(dp[n][m], dp[n][i]+dp[i+1][m]+sum);
    }
}

int main()
{
    ll n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j]=-1;
        }
    }
    solve(0, n-1);
    cout << dp[0][n-1];
}