#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  // 各iについての最大値を(i+1)、2つめの添え字は反転している場合は0、選んでたら1
  ll dp[(n + 1)][2];
  dp[0][0] = 0;
  dp[0][1] = INT_MIN;
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = max({dp[i][0] + a.at(i), dp[i][1] - a.at(i)});
    dp[i + 1][1] = max({dp[i][0] - a.at(i), dp[i][1] + a.at(i)});
  }
  cout << dp[n][0] << endl;
  return 0;
}
