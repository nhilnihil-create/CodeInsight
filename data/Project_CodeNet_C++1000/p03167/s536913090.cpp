#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
  int DIV = 1e+9 + 7;
  int H, W; cin >> H >> W;
  bool A[H][W]; string str;
  for (int i = 0; i < H; i++) {
    cin >> str;
    for (int j = 0; j < W; j++) {
      A[i][j] = (str[j] == '.');
    }
  }
  long dp[H][W];
  dp[0][0] = 1;
  for (int j = 1; j < W; j++) dp[0][j] = A[0][j] * dp[0][j-1];
  for (int i = 1; i < H; i++) dp[i][0] = A[i][0] * dp[i-1][0];
  for (int i = 1; i < H; i++) {
    for (int j = 1; j < W; j++) {
      dp[i][j] = (A[i][j] * (dp[i-1][j] + dp[i][j-1])) % DIV;
    }
  }
  cout << dp[H-1][W-1] << endl;
}