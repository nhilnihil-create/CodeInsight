#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> c(h+1, vector<char>(w+1));
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }
  vector<vector<int>> dp(h+1, vector<int>(w+1));
  dp[1][1] = 1;
  for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
      if(i == 1 && j == 1) continue;
      else if(c[i][j] == '#') dp[i][j] = 0;
      else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
    }
  }
  cout << dp[h][w] << endl;
  return 0;
}
