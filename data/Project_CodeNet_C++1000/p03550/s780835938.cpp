#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[2][2010], a[2010];
int N, Z, W;
const int INF = 1000000000;

int rec(int i, int j) {
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int ret;
  if (i == 0) {
    ret = -2 * INF;
    for (int k = j + 1; k <= N; k++) {
      ret = max(ret, rec(1, k));
    }
    ret = max(ret, abs(a[N] - a[j - 1]));
  } else if (i == 1) {
    ret = 2 * INF;
    for (int k = j + 1; k <= N; k++) {
      ret = min(ret, rec(0, k));
    }
    ret = min(ret, abs(a[N] - a[j - 1]));
  }
  dp[i][j] = ret;
  return ret;
}

int main() {
  cin >> N >> Z >> W;
  a[0] = W;
  for (int i = 0; i < N; i++) cin >> a[i + 1];
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 1) << endl;
}
