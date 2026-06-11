#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> dp(10, vector<int>(10, 0));
  for(int i = 0; i < 10; ++i) {
    for(int j = 0; j < 10; ++j) {
      cin >> dp[i][j];
    }
  }
  vector<int> as;
  int a;
  for(int h = 0; h < H; ++h) {
    for(int w = 0; w < W; ++w) {
      cin >> a;
      if(a >= 0) {
        as.push_back(a);
      }
    }
  }

  for(int k = 0; k < 10; ++k) {
    for(int i = 0; i < 10; ++i) {
      for(int j = 0; j < 10; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  int ans = 0;
  for(auto a : as) {
    ans += dp[a][1];
  }
  cout << ans << endl;
  return 0;
}