// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
const ll MAX_N = 16;
vector<vector<ll>> a(MAX_N,vector<ll>(MAX_N));
vector<ll> dp(1ll<<MAX_N,-1);
ll n;
ll solve(ll s){
  if(dp[s]!=-1) return dp[s];
  ll res = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if((s&(1ll<<i))&&(s&(1ll<<j))){
        res += a[i][j];
      }
    }
  }
  for(ll t=(s-1)&s;t>0;t=(t-1)&s){
    res = max(res,solve(t)+solve(s^t));
  }
  return dp[s] = res;
}
signed main(){
  init_io();
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  cout << solve((1ll<<n)-1)<<endl;
}
