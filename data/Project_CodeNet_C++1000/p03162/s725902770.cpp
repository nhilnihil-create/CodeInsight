#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> p(n, vector<int>(3));
  rep(i,n) rep(j,3) cin >> p[i][j];
  vector<vector<int>> dp(n+1, vector<int>(3));
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(j == k) continue;
        dp[i][k] =  max(dp[i][k], dp[i-1][j] + p[i-1][k]);
      }
    }
  }
  int ans = 0;
  rep(i,3) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}