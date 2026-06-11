/**
 *    author:  math2do
 *    created: 06.09.2020 12:23:23
**/

#include <bits/stdc++.h>

using namespace std;

const int mod = (int) (1e9 + 7);

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vector <int> > can(n, vector <int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> can[i][j];
    } 
  }
  vector <int> dp(1 << n);
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n) - 1; mask++) {
    int i = __builtin_popcount(mask);
    for (int j = 0; j < n; j++) {
      if (can[i][j] && !(mask & (1 << j))) {
        int m = mask ^ (1 << j);
        add(dp[m], dp[mask]);
      } 
    } 
  } 

  cout << dp[(1 << n) - 1] << endl;
  return 0;
}
