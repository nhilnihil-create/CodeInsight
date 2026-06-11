#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF INT_MAX

void solve()
{
    ll n,i;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(3));
    vector<vector<ll>> dp(n,vector<ll>(3));

    for(i=0;i<n;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }

    dp[0][0]=v[0][0];
    dp[0][1]=v[0][1];
    dp[0][2]=v[0][2];

    for(i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+v[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+v[i][1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+v[i][2];
    }

    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}

int main()
{
    solve();
}
