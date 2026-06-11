#include<bits/stdc++.h>
const int MOD = 1e9+7;
using namespace std;
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  vector<vector<int>> dp(h, vector<int>(w, 0));
  for(int i=0; i<h; i++) {
 	for(int j=0; j<w; j++) {
     cin >> grid[i][j];
    }
  }
  dp[0][0] = (grid[0][0] == '.') ? 1 : 0;
  for(int i=1; i<h; i++) {
    if(grid[i][0] == '.') {
      dp[i][0] = dp[i-1][0];
    }
  }
  for(int i=1; i<w; i++) {
    if(grid[0][i] == '.') {
      dp[0][i] =dp[0][i-1];
    }
  }
   for(int i=1; i<h; i++) {
 	for(int j=1; j<w; j++) {
     if(grid[i][j] == '.') {
       dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
     }
    }
  }
  cout << dp[h-1][w-1]%MOD;
  return 0;
}

