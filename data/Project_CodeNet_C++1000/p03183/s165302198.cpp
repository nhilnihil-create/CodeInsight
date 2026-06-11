/*
 *    author:  Gary Shih
 *    created: 2020-05-07 15:29:12
 */
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<1>(a[i]) >> get<2>(a[i]) >> get<3>(a[i]);
    get<0>(a[i]) = get<1>(a[i]) + get<2>(a[i]);
  }
  sort(a.rbegin(), a.rend());
  vector<long long> dp(2e4 + 1);
  for (int i = 0; i < n; ++i) {
    int w = get<1>(a[i]), s = get<2>(a[i]), v = get<3>(a[i]);
    for (int j = 0; j <= s; ++j)
      if (j + w < (int)dp.size()) dp[j] = max(dp[j], dp[j + w] + v);
    for (int j = dp.size() - 2; j >= 0; --j) dp[j] = max(dp[j], dp[j + 1]);
  }
  cout << dp[0] << '\n';
}
