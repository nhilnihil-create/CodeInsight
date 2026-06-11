#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int N, M;
long long X[1005], Y[1005], Z[1005];
long long dp[1005][1005][8];

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  for (int i = 0; i < 1005; i++) {
    for (int j = 0; j < 1005; j++) {
      for (int k = 0; k < 8; k++) {
        dp[i][j][k] = -1e15;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    dp[0][0][i] = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= M; j++) {
      for (int k = 0; k < 8; k++) {
        chmax(dp[i + 1][j][k], dp[i][j][k]);
      }
      chmax(dp[i + 1][j + 1][0], dp[i][j][0] + X[i] + Y[i] + Z[i]);
      chmax(dp[i + 1][j + 1][1], dp[i][j][1] + X[i] + Y[i] - Z[i]);
      chmax(dp[i + 1][j + 1][2], dp[i][j][2] + X[i] - Y[i] + Z[i]);
      chmax(dp[i + 1][j + 1][3], dp[i][j][3] + X[i] - Y[i] - Z[i]);
      chmax(dp[i + 1][j + 1][4], dp[i][j][4] - X[i] + Y[i] + Z[i]);
      chmax(dp[i + 1][j + 1][5], dp[i][j][5] - X[i] + Y[i] - Z[i]);
      chmax(dp[i + 1][j + 1][6], dp[i][j][6] - X[i] - Y[i] + Z[i]);
      chmax(dp[i + 1][j + 1][7], dp[i][j][7] - X[i] - Y[i] - Z[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < 8; i++) {
    chmax(ans, dp[N][M][i]);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
