/**
 *    author:  math2do
 *    created: 04.09.2020 15:17:55 IST
**/

#include <bits/stdc++.h>

using namespace std;

#define max(...) max({__VA_ARGS__})

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m = 3;
  cin >> n;
  vector <vector <int> > mat(n, vector <int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    } 
  } 
  vector <vector <int> > dp(n, vector <int>(m, 0));
  dp[0][0] = mat[0][0];
  dp[0][1] = mat[0][1];
  dp[0][2] = mat[0][2];
  
  for (int i = 1; i < n; i++) {
    dp[i][0] = mat[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = mat[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = mat[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
  } 
  
  cout << max(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]) << endl;
  return 0;
}
