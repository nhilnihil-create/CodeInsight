#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[0][0] = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') continue;
      if (i + 1 < h && a[i+1][j] == '.') {
        dp[i+1][j] += dp[i][j];
        if (dp[i+1][j] >= mod) {
          dp[i+1][j] -= mod;
        }
      }
      if (j + 1 < w && a[i][j+1] == '.') {
        dp[i][j+1] += dp[i][j];
        if (dp[i][j+1] >= mod) {
          dp[i][j+1] -= mod;
        }
      }
    }
  }
  cout << dp[h-1][w-1] << '\n';
  return 0;
}
