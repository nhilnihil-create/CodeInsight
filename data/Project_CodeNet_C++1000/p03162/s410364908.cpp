#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector< vector<int> > abc(n, vector<int>(3));
  for (int i = 0; i < n; ++i) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

  vector< vector<int> > dp(n + 1, vector<int>(3, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
	if (j == k) continue;
	dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + abc[i][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; ++i) ans = max(ans, dp[n][i]);
  cout << ans << '\n';
  return 0;
}
