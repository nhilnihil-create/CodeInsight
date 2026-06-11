#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  const int N = 200000;
  const int md = 1000000007;
  vector<int> dp(n + 1, 0);
  vector<int> last(N, -1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = dp[i];
    if (last[c[i]] != -1 && last[c[i]] != i - 1) {
      (dp[i + 1] += dp[last[c[i]] + 1]) %= md;
    }
    last[c[i]] = i;
  }
  cout << dp[n] << '\n';
  return 0;
}
