#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD=1e9+7;
string s;
ll dp[200005];
ll a[200005];
map<ll,ll> mp;
map<ll,ll>mpp;
ll n;
ll solve(ll i)
{
    if (dp[i]!=-1)
        return dp[i];
    if(i==n-1)
        return 0;
    if(i>=n)
    return 1e18;
    return dp[i] = min (fabs(a[i+1]-a[i])+solve(i+1),fabs(a[i+2]-a[i])+solve(i+2));
}

int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    ll ans=0;
    cout<<solve(0);
    return 0;
}
