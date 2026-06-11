#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  int a[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  
  vector<int> dp(1<<n, 0);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    vector<int> tmp(1<<n, 0);
    for (int j = 0; j < (1<<n); ++j) {
      if (__builtin_popcount(j) != i + 1) continue;
      for (int b = 0; b < n; ++b) {
        if (a[i][b] && (j>>b)&1) {
          tmp[j] = (tmp[j] + dp[j^(1<<b)]) % M;
        }
      }
    }
    swap(tmp, dp);
  }
  cout << dp[(1<<n)-1] << '\n';
}
