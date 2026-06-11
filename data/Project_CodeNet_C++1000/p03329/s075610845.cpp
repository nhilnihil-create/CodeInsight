#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

// 余裕を持たせないと WA になる
const int MAX_N = 110000;

int main() {
  int n;
  cin >> n;

  vector<int> dp(MAX_N, n);  // INF の気持ち
  dp[0] = 0;

  // 貰う DP --- dp[i] に遷移を集める
  for (int i = 1; i <= n; i++) {
    // 1, 6, 6^2, ..., を試す (i を超えない範囲で)
    for (int pow6 = 1; pow6 <= i; pow6 *= 6)
      dp[i] = min(dp[i], dp[i - pow6] + 1);

    // 1, 9, 9^2, ..., を試す (i を超えない範囲で)
    for (int pow9 = 1; pow9 <= i; pow9 *= 9)
      dp[i] = min(dp[i], dp[i - pow9] + 1);
  }

  cout << dp[n] << endl;
}
