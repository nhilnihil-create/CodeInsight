#include <bits/stdc++.h>
using namespace std;

const int inf = 1001001001;

int main() {
  string s;
  cin >> s;

  vector<int> t(1 << 26, inf), dp(s.size() + 1, inf);
  dp[0] = t[0] = 0;

  int x = 0;
  for (int i = 1; i <= s.size(); ++i) {
    x ^= (1 << (s[i - 1] - 'a'));
    for (int j = 0; j < 26; ++j) {
      dp[i] = min(dp[i], t[x ^ (1 << j)] + 1);
    }
    dp[i] = min(dp[i], t[x] + 1);

    t[x] = min(t[x], dp[i]);
  }

  cout << dp[s.size()] << endl;
}
