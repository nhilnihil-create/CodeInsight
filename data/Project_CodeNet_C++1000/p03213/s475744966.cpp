#include<iostream>
#include<cmath>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1c(i, n) for (int i = 1; i <= (int)(n); i++)

using namespace std;

int N, dp[100][2][3];
map<int, int> m;

void solve() {
  rep1c(i, N) {
    int j = 2;
    int k = i;
    while (k > 1 || i >= j) {
      if (k % j == 0) {
        m[j] += 1;
        k /= j;
      } else {
        j++;
      }
    }
  }
  dp[0][0][0] = 1;
  int ki = 1;
  for ( auto it : m ) {
    rep(i, 2) rep(j, 3) dp[ki][i][j] = dp[ki-1][i][j];
    if(it.second >= 74) {
      dp[ki][1][2] += dp[ki-1][0][0];
    }
    if(it.second >= 24) {
      dp[ki][1][2] += dp[ki-1][1][0];
      dp[ki][0][2] += dp[ki-1][0][0];
    }
    if(it.second >= 14) {
      dp[ki][1][2] += dp[ki-1][0][1];
      dp[ki][1][1] += dp[ki-1][0][0];
    }
    if(it.second >= 4) {
      dp[ki][1][2] += dp[ki-1][1][1];
      dp[ki][1][1] += dp[ki-1][1][0];
      dp[ki][0][2] += dp[ki-1][0][1];
      dp[ki][0][1] += dp[ki-1][0][0];
    }
    if(it.second >= 2) {
      dp[ki][1][2] += dp[ki-1][0][2];
      dp[ki][1][1] += dp[ki-1][0][1];
      dp[ki][1][0] += dp[ki-1][0][0];
    }
    ki++;
  }
  cout << dp[m.size()][1][2] << endl;
}

int main() {
  cin >> N;
  solve();
  return 0;
}
