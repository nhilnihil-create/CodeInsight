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
    ll n;cin>>n;
    ll h[n];
    fo(i,0,n)   cin>>h[i];
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    for(ll i=1;i<n;i++)
    {
        dp[i] = abs(h[i]-h[i-1])+dp[i-1];
        if(i>1)
            dp[i] = min(dp[i],abs(h[i]-h[i-2])+dp[i-2]);
    }
    cout << dp[n-1];
}

