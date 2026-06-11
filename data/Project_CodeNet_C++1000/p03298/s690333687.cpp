#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string left = s.substr(0, n);
  string right = s.substr(n, n+n);
  reverse(begin(right), end(right));
  vector<vector<int>> dp(n+1, vector<int>(n+1));
  int64_t res = 0;
  for (int mask = 0; mask < (1<<n); ++mask) {
    // clear
    for (auto &x : dp) fill(begin(x), end(x), 0);

    string a, b;
    for (int i = 0; i < n; ++i) ((mask >> i & 1) ? a : b) += left[i];
    dp[0][0] = 1;
    for (int i = 0; i <= a.size(); ++i) for (int j = 0; j <= b.size(); ++j) {
      if (i < a.size() && a[i] == right[i+j]) dp[i+1][j] += dp[i][j];
      if (j < b.size() && b[j] == right[i+j]) dp[i][j+1] += dp[i][j];
    }
    res += dp[a.size()][b.size()];
  }

  cout << res << endl;
  return 0;
}
