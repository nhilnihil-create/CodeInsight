/**
 *    author:  tourist
 *    created: 25.12.2019 00:15:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> w(n), s(n), v(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> s[i] >> v[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return w[i] + s[i] < w[j] + s[j];
  });
  vector<long long> dp(w[order.back()] + s[order.back()] + 1, 0);
  for (int i : order) {
    for (int j = s[i]; j >= 0; j--) {
      dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
