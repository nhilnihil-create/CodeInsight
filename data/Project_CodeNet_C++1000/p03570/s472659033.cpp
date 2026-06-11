#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

main() {
  string s; cin >> s;

  int opt{}, cur{};
  vector<int> dp(1 << 26, INF);
  dp[0] = 0;
  for (auto&& c : s) {
    cur ^= 1 << (c - 'a');
    opt = dp[cur];
    for (int i = 0; i < 26; i++) opt = min(opt, dp[cur ^ (1 << i)]);
    dp[cur] = min(dp[cur], ++opt);
  }
  cout << opt << endl;
}
