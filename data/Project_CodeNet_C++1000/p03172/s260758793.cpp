#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
  ll n,k;
  cin>>n>>k;
  ll a[n+1];
  for(ll i=1;i<=n;i++)
      cin>>a[i];

  ll dp[n+1][k+1];
  memset(dp,0,sizeof(dp));

  dp[0][0]=1;
  for(ll i=1;i<=n;i++)
  {
    ll pref[k+1]={0};
    pref[0]=dp[i-1][0]%mod;
    for(ll j=1;j<=k;j++)
      pref[j]=(pref[j-1]+dp[i-1][j])%mod;
    for(ll j=0;j<=k;j++)
    {
      if(j<=a[i])
        dp[i][j]=pref[j]%mod;
      else
      {
        dp[i][j]=(pref[j]-pref[j-a[i]-1]+mod)%mod;
      }
    }
  }

  cout<<dp[n][k]<<endl;
  return 0;
}