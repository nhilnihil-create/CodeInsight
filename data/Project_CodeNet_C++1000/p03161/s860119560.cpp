#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;

int main()
{
    ll n,k;cin>>n>>k;
    ll h[n];
    fo(i,0,n)   cin>>h[i];
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(ll i=1;i<n;i++)
    {
        dp[i]=1e9+7;
        for(ll j=i-1;j>=i-k&&j>=0;j--)
        {
            dp[i] = min(dp[i],abs(h[i]-h[j])+dp[j]);
        }
        
    }
    cout << dp[n-1];
}

