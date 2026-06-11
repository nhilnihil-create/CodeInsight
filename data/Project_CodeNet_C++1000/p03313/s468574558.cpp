#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n; n = (1 << n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n);
  int best = 0;
  for (int i = 0; i < n; ++i) {
    dp[i].push_back(i);
    for (int j = 1; j < n; j *= 2) {
      if (i & j) {
        for (auto x : dp[i ^ j])
          dp[i].push_back(x);
      }
    }
    sort(dp[i].begin(), dp[i].end());
    dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());
    sort(dp[i].begin(), dp[i].end(), [&](int i, int j) { return a[i] > a[j]; });
    if (i > 0) {
      dp[i].resize(2);
      best = max(best, a[dp[i][0]] + a[dp[i][1]]);
      cout << best << "\n";
    }
  }
  cout << endl;
  return 0;
}
