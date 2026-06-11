#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
  ll MOD = 1000000007;
  int n;
  cin >> n;
  vvi a(n, vi(n));
  rep(i,n) rep(j,n) cin >> a[i][j];
  vl dp(1<<n);
  dp[0] = 1;
  for(int s=1; s<(1<<n); s++){
    int i = __builtin_popcount(s);
    rep(j,n){
      if(a[i-1][j] == 1 && s >> j & 1){
        dp[s] += dp[s ^ (1<<j)];
        dp[s] %= MOD;
      }
    }
  }
  //rep(i, 1<<n) cout << dp[i] << " ";
  cout << dp[(1<<n)-1] << endl;
}
