#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
void solve()
{
  ll n;
  cin>>n;
  ll g=1ll<<n;
  ll a[n+1][n+1];
  for(int x=0;x<n;x++)
  for(int y=0;y<n;y++)
  cin>>a[x][y];
  ll dp[g]={0};
  for(ll x=0;x<g;x++)
  {   vector<ll> ae;
      for(int y=0;y<n;y++)
      {
          if(x&(1ll<<y))
            ae.push_back(y);
      }
      for(int i=0;i<ae.size();i++)
      for(int y=i+1;y<ae.size();y++)
          dp[x]+=a[ae[i]][ae[y]];
    dp[x]=max(dp[x],0ll);
  }
  for(ll x=0;x<g;x++)
  {   vector<ll> ae;
      for(int y=0;y<n;y++)
      {
          if(x&(1ll<<y))
            ae.push_back(y);
      }
      ll r=1ll<<((ll)ae.size());
      for(ll i=0;i<r;i++)
      {
          ll w=0;
          ll e=0;
          for(ll t=0;t<ae.size();t++)
          {
              if(i&(1ll<<t))
                w|=(1ll<<ae[t]);
            else
                e|=(1ll<<ae[t]);
          }
          dp[x]=max(dp[x],dp[w]+dp[e]);
      }
  }
  cout<<dp[g-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
}
