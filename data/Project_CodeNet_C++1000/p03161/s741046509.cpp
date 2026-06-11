//Frog-1
#include<bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define N (ll)(1e7+5)
#define mod (ll)(1e9+7)

using namespace std;

int main()
{
    ll n,k; cin>>n>>k;
    vector<ll> dp(n),v(n);
    for(auto &x:v)
        cin>>x;
    dp[1] = abs(v[1]-v[0]);
    for(ll i=2;i<n;i++)
    {
        dp[i] = abs(v[i]-v[i-1])+dp[i-1];
        for(ll j=2;j<=min(k,i);j++)
            dp[i] = min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
