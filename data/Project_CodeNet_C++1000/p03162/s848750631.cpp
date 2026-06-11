#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(vector<vector<int>>& mat) {
  int n = mat.size();
  vector<vector<int>> dp(n, vector<int>(3, 0));
  for(int i = 0; i < 3; ++i) {
    dp[0][i] = mat[0][i];
  }
  for(int i = 1; i < n; ++i) {
    for(int j = 0; j < 3; ++j) {
      for(int k = 0; k < 3; ++k) {
        if (j == k) {
          continue;
        }
        dp[i][j] = max(dp[i][j], dp[i-1][k] + mat[i][j]);  
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < 3; ++i) {
    ans = max(ans, dp[n-1][i]);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(3, 0));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 3; ++j) {
      cin >> mat[i][j];
    }
  }
  cout << solve(mat) << '\n';
  return 0;
}

