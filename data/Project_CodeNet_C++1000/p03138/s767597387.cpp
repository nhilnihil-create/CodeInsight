#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n,k;
  cin >> n >> k;
  vector<ll> msk(50,0);
  rep(i,n){
    ll x;cin >> x;
    rep(j,50)msk[j] += (x >> j & 1);
  }
  vector<vector<ll>> dp(50,vector<ll>(2,-1));
  dp[44][1] = 0;
  for(int i = 43;i >= 0;i--){
    if(dp[i+1][0] >= 0)dp[i][0] = max(dp[i][0],dp[i+1][0]+max(n-msk[i],msk[i])*(1ll << i));
    if(dp[i+1][1] >= 0){
      if(k >> i & 1){
        dp[i][1] = max(dp[i][1],dp[i+1][1]+(n-msk[i])*(1ll << i));
        dp[i][0] = max(dp[i][0],dp[i+1][1]+msk[i]*(1ll << i));
      }else{
        dp[i][1] = max(dp[i][1],dp[i+1][1]+msk[i]*(1ll << i));
      }
    }
  }
  ll res = 0;
  res = max({res,dp[0][0],dp[0][1]});
  cout << res << endl;




  return 0;
}