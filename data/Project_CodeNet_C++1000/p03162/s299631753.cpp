#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;

// 入力
int N;
long long h[100010][3];

// DP テーブル
long long dp[100010][3] = {};

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; ++i) for (int j = 0; j < 3; j++) cin >> h[i][j];

  // ループ
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j==k) continue;
        chmax(dp[i + 1][k], dp[i][j]+ h[i][k]); //dp[1][]には1日目の結果…
      }
    }
  }
    // 答え
    cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}