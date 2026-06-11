#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll n;
ll a[30][30];
ll dp[30][ll(1<<21)];

ll solve(ll cm, ll mask){
  if(cm>n)return 1;
  if(dp[cm][mask]!= -1)return dp[cm][mask];
  ll ways =0;
  for(ll i=1;i<=n; i++){
    if(a[cm][i]==0)continue;
    if(mask&1<<(i-1))continue;
    ways += solve(cm+1,mask|1<<(i-1))%mod;
  }
  dp[cm][mask] = ways%mod;
  return dp[cm][mask]%mod;
}

int main(){
  fastio
  cin>>n;
  for(ll i=1; i<=n; i++){
    for(ll j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<solve(1ll,0ll)<<"\n";
  return 0;
}