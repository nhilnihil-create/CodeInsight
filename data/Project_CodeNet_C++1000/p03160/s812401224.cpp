#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  vector<int> dp(n + 5, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }

  cout << dp[n - 1] << '\n';
  return 0;
}
