#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<double> p(n);
  rep(i,n) cin >> p[i];
  vector<vector<double>> dp(3100, vector<double>(3100));
  dp[0][0] = 1.0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      dp[i+1][j+1] += dp[i][j] * p[i];
      dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
    }
  }
  double ans = 0.0;
  for(int j = n/2 + 1; j <= n; j++) ans += dp[n][j];
  printf("%.10f", ans);
  return 0;
}
