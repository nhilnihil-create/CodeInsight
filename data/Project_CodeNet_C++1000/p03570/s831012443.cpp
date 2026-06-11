#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  string s;
  cin >> s;

  map<int, int> dp;

  dp[0] = 0;

  int xs = 0;

  const int n = s.size();

  vector<int> opt(n, 1e9);
  for (int i = 0; i < n; i++) {
    xs ^= 1 << s[i] - 'a';

    for (int j = 0; j < 26; j++) {
      if (dp.count(xs ^ 1 << j)) {
        opt[i] = min(opt[i], dp[xs ^ 1 << j] + 1);
      }
    }
    if (!dp.count(xs)) dp[xs] = 1e9;
    dp[xs] = min(dp[xs], opt[i]);
  }
  if (xs == 0) {
    opt[n - 1] = 1;
  }

  cout << opt[n - 1] << endl;
}