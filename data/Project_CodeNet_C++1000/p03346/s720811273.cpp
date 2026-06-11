#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> id(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    id[p[i]] = i;
  }
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    dp[p[i]] = 1;
    if (p[i]) dp[p[i]] = dp[p[i] - 1] + 1;
  }
  cout << n - *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}
