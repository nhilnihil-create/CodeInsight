/**
 *    author:  math2do
 *    created: 04.09.2020 18:17:57 IST
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
  int n, m;
  cin >> n >> m;
  vector <vector <char> > mat(n, vector <char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    } 
  } 
  if (mat[0][0] == '#') {
    cout << 0 << endl;
    return 0;
  } 
  vector <vector <int> > dp(n, vector <int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') {
	dp[i][j] = 0;
	continue;
      } else {
	if (i == 0 && j == 0) {
	  dp[0][0] = 1;
	} else if (i == 0) {
	  dp[i][j] = dp[i][j - 1];
	} else if (j == 0) {
	  dp[i][j] = dp[i - 1][j];
	} else {
	  add(dp[i][j], dp[i - 1][j]);
	  add(dp[i][j], dp[i][j - 1]);
	}
      } 
    } 
  } 
  
  cout << dp[n - 1][m - 1] << endl;
  return 0;
}
