#include <bits/stdc++.h>
using namespace std;
string s;
int mt[1 << 26];
int main() {
  fill(mt, mt + (1 << 26), 1E6);
  cin >> s;
  mt[0] = 0;
  const int n = s.size();
  vector<int> dp(n + 1);
  iota(dp.begin(), dp.end(), 0);
  int state = 0;
  for (int i = 1; i <= n; ++i) {
    // cout << "i: " << i  << endl;
    const int cc = s[i - 1] - 'a';
    state ^= (1 << cc);

    for (int k = 0; k < 26; ++k) {
      int ps = state ^ (1 << k);
      dp[i] = min(dp[i], 1 + mt[ps]);
    }
    // cout << dp[i] << endl;
    
    dp[i] = min(dp[i], 1 + mt[state]);
    mt[state] = min(dp[i], mt[state]);

    // cout << dp[i] << endl;
  }

  cout << dp[n] << endl;
}