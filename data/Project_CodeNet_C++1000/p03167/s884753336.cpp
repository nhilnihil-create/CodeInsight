#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10;
const ll MOD = 1000000007;
int dp[1010][1010];
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  REP(i, H) cin >> a[i];
  dp[0][0] = 1;
  dp[H - 1][W - 1] = 0;
  REP(i, H) {
    int b = 10;
    REP(j, W) {
      if (j < W - 1) {
        if (a[i][j + 1] == '.') {
          dp[i][j + 1] += dp[i][j];
          dp[i][j + 1] %= MOD;
        }
      }
      if (i < H - 1) {
        if (a[i + 1][j] == '.') {
          dp[i + 1][j] += dp[i][j];
          dp[i + 1][j] %= MOD;
        }
      }
    }
  }
  // if (dp[H - 1][W - 1] == INF) dp[H - 1][W - 1] = 0;
  cout << dp[H - 1][W - 1] << endl;
}