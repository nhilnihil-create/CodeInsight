#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  long long K; cin >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  const int INF = 1000000007;
  // dp[i][j] := 上から i 桁目を決めたときの最大値で、j = 1 のときは K 未満確定
  vector<vector<long long>> dp(41, vector<long long>(2, -INF));
  dp.at(0).at(0) = 0;
  for (int i = 0; i < 40; i++) {
    long long mask = 1LL << (39 - i);
    int num = 0;  // 数列 A で上から i+1 桁目のビットが 1 である要素数
    for (int j = 0; j < N; j++) {
      if (A.at(j) & mask) num++;
    }

    // dp[i][0] からの遷移 (K の i+1 桁目が 0 か 1 で対応を変える)
    if (dp.at(i).at(0) >= 0) {
      if (K & (1LL << (39 - i))) {
        // i+1 桁目に 0 を入れる (未満フラグ立つ)
        dp.at(i+1).at(1) = max(dp.at(i+1).at(1), dp.at(i).at(0) + mask * num);
        // i+1 桁目に 1 を入れる
        dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(0) + mask * (N-num));
      }
      else {
        // i+1 桁目には 0 しか入れられない (1 だと K を超えてしまう)
        dp.at(i+1).at(0) = max(dp.at(i+1).at(0), dp.at(i).at(0) + mask * num);
      }
    }
    // dp[i][1] からの遷移 (i+1 桁目は 0 か 1 を自由に決める)
    if (dp.at(i).at(1) >= 0) {
      dp.at(i+1).at(1) = max(dp.at(i+1).at(1), dp.at(i).at(1) + mask * max(num, N-num));
    }
  }
  cout << max(dp.at(40).at(0), dp.at(40).at(1)) << endl;
}