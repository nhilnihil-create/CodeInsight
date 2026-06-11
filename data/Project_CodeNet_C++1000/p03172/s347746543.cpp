#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int mod = 1e9 + 7;
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n, vector<int>(K + 1, 0));
  for (int j = 0; j <= a[0]; ++j) {
    if (j <= K)
      dp[0][j] =  1;
  }
  for (int i = 1; i < n; ++i)  {
    int acc = 0;
    for (int k = 0; k <= K; ++k) {
      acc += dp[i-1][k];
      if (acc >= mod) {
        acc -= mod;
      }
      if (k - a[i] - 1 >= 0) {
        acc -= dp[i-1][k-a[i]-1];
        if (acc < 0) {
          acc += mod;
        }
      }
      dp[i][k] += acc;
      if (dp[i][k] >= mod) {
        dp[i][k] -= mod;
      }
    }
  }
  cout << dp[n-1][K] << '\n';

  return 0;
}
