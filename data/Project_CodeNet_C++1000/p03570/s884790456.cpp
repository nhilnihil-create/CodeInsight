#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  unordered_map<int, int> mt;
  mt[0] = 0;
  const int n = s.size();
  vector<int> dp(n + 1);
  iota(dp.begin(), dp.end(), 0);
  int state = 0;
  for (int i = 1; i <= n; ++i) {
    const int cc = s[i - 1] - 'a';
    state ^= (1 << cc);

    for (int k = 0; k < 26; ++k) {
      int ps = state ^ (1 << k);
      if (mt.count(ps)) {
        dp[i] = min(dp[i], 1 + mt[ps]);
      }
    }

    if (mt.count(state)) {
      dp[i] = min(dp[i], 1 + mt[state]);
      mt[state] = min(dp[i], mt[state]);
    } else mt[state] = dp[i];
    // cout << dp[i] << endl;
  }

  cout << dp[n] << endl;
}