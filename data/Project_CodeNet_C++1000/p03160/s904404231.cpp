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
    ll n;cin>>n;
    vector<ll> dp(n),v(n);
    for(auto &x:v)
        cin>>x;
    dp[0] = 0;
    dp[1] = abs(v[1]-v[0]);
    for(ll i=2;i<n;i++)
        dp[i] = min(abs(v[i]-v[i-1])+dp[i-1],abs(v[i]-v[i-2])+dp[i-2]);
    cout<<dp[n-1]<<endl;
    return 0;
}
