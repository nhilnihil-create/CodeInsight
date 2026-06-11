#include <bits/stdc++.h>

using namespace std;

const long long inf = 1ll << 60;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> q(n + 1);
  for (int i = 1; i <= n; ++i) {
    q[p[i]] = i;
  }
  vector<long long> dp(n + 1, inf);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    vector<long long> new_dp(n + 1, inf);
    for (int j = 0; j < i; ++j) {
      if (dp[j] != inf) {
        if (q[i] > q[j]) {
          new_dp[i] = min(new_dp[i], dp[j]);
          new_dp[j] = min(new_dp[j], dp[j] + b);
        } else {
          new_dp[j] = min(new_dp[j], dp[j] + a);
        }
      }
    }
    swap(dp, new_dp);
  }
  cout << *min_element(dp.begin(), dp.end()) << "\n";
  return 0;
}
