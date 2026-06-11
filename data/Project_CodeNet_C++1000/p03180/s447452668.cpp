/**
 *    author:  tourist
 *    created: 24.12.2019 19:44:51       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<long long> sub(1 << n);
  for (int t = 1; t < (1 << n); t++) {
    int i = 0;
    while (!(t & (1 << i))) {
      ++i;
    }
    sub[t] = sub[t ^ (1 << i)];
    for (int j = i + 1; j < n; j++) {
      if (t & (1 << j)) {
        sub[t] += a[i][j];
      }
    }
  }
  vector<long long> dp(1 << n);
  for (int t = 1; t < (1 << n); t++) {
    int nt = t;
    int u = nt;
    while (true) {
      dp[t] = max(dp[t], dp[t ^ u] + sub[u]);
      if (u == 0) {
        break;
      }
      u = (u - 1) & nt;
    }
  }
  cout << dp.back() << '\n';
  return 0;
}