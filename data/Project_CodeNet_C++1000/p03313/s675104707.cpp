#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }

  auto merge = [&](pair<int,int> p, int i) {
    int x, y;
    tie(x, y) = p;
    if (x == i || y == i) return p;
    if (x == -1 || a[i] > a[x]) {
      return make_pair(i, x);
    } else if (y == -1 || a[i] > a[y]) {
      return make_pair(x, i);
    } else {
      return p;
    }
  };

  vector<pair<int,int>> dp(1 << n, make_pair(-1, -1));

  for (int i = 0; i < (1 << n); i++) {
    dp[i] = merge(dp[i], i);
    for (int j = 0; j < n; j++) {
      dp[i | (1 << j)] = merge(dp[i | (1 << j)], dp[i].first);
      dp[i | (1 << j)] = merge(dp[i | (1 << j)], dp[i].second);
    }
  }

  vector<int> ans(1 << n);
  for (int i = 1; i < (1 << n); i++) {
    ans[i] = a[dp[i].first] + a[dp[i].second];
    ans[i] = max(ans[i], ans[i - 1]);
  }

  for (int i = 1; i < (1 << n); i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
