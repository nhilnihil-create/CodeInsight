#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  vector<vector<ll>> dp(n, vector<ll>(3));
  rep(i,n)rep(j,3) cin >> a[i][j];
  rep(i,3) dp[0][i] = a[0][i];
  for(int i=0; i<n-1; ++i) {
    for(int j=0; j<3; ++j) {
      for(int k=0; k<3; ++k) {
        if (j == k) continue;
        dp[i+1][k] = max(dp[i+1][k], dp[i][j]+a[i+1][k]);
      }
    }
  } 
  ll ans = 0;
  rep(i,3) ans = max(ans, dp[n-1][i]);
  cout << ans << endl;
  return 0;
}