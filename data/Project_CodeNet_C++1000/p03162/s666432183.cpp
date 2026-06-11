#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {

  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(3, 0));
  dp[0] = a[0];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (k != j) {
          dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
        }
      }
    }
  }
  cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
  return 0;
}
