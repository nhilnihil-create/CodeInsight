#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  vector<ll> pre(200200,0);
  vector<ll> dp(n+1,0);
  dp[0] =  1;
  v.erase(unique(ALL(v)),v.end());
  rep(i,v.size()){
    (dp[i+1] += pre[v[i]])%= MOD;
    (pre[v[i]] += dp[i])%= MOD;
    (dp[i+1] += dp[i])%= MOD;
  }
  cout << dp[v.size()] << endl;





  return 0;
}