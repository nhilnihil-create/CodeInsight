#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minm;
ll dp[100001];
int fn(ll a[],ll n,ll k)
{
    if(n==0)
    {
        dp[n] = min(minm,dp[n]);
        return dp[n];
    }
    if(dp[n] != INT_MAX)
    {
        return dp[n];
    }
    if(k>=2 && n>=2)
    {
        ll p = 0;
        for(ll i = n-1; i>=max(n-k,p); i--)
        {
            ll x = abs(a[n]-a[i]);
            dp[n] = min(x+fn(a,i,k),dp[n]);
        }
    }
    else
    {
        ll x = abs(a[n]-a[n-1]);
        dp[n] = x+fn(a,n-1,k);
    }
    // return dp[n];
    return dp[n];
}
int main()
{
    ll i,n,k;
    cin>>n>>k;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        dp[i]=INT_MAX;
    }
    // memset(dp,-1,sizeof(dp));
    dp[0] = INT_MAX;
    fn(a,n-1,k);
    // cout<<"\n\n\n\n";
    // for(i=0; i<n; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    cout<<dp[n-1]<<"\n";
    return 0;
}