#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector <string> grid(	n);
  ffor(n) cin >> grid[i];
  vector <vector <int>> dp(n, vector <int>(m));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (i + 1 < n && grid[i + 1][j] != '#') {
        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % INF;
      }
      if (j + 1 < m && grid[i][j + 1] != '#') {
        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % INF;
      }
    }
  }
  cout << dp[n - 1][m - 1] << '\n';
}