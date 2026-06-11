#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<vector<double>> dp(n, vector<double>(n + 1, 0.0));
  dp[0][1] = p[0];
  dp[0][0] = 1.0 - p[0];
  for (int i = 1; i < n; ++i) {
    dp[i][0] = (i > 0 ? dp[i-1][0]: 1.0) * (1.0 - p[i]);
    for (int j = 1; j <= i + 1; ++j) {
      dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1.0 - p[i]);
    }
  }

  double ans = 0.0;
  for (int i = n/2 + 1; i <= n; ++i) {
    ans += dp[n-1][i];
  }
  cout << setprecision(10) << ans << '\n';

  return 0;
}


/*
 dp[i][j]: probability of j heads using i first coins
 * C(n, 0)
 * total 2^n
 */
