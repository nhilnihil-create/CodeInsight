#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 1050;
const long long INF = 1e18;

int n, m;
long long x[MAXN], y[MAXN], z[MAXN];
long long dp[MAXN][MAXN];
long long ans = -INF;

int getBit(long long x, int pos) {
  return (x & (1ll << pos)) > 0 ? 1 : 0;
}

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
  }

  for (int mask = 0; mask < (1 << 3); mask++) {
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
      if (getBit(mask, 0)) {
        x[i] = -x[i];
      }
      if (getBit(mask, 1)) {
        y[i] = -y[i];
      }
      if (getBit(mask, 2)) {
        z[i] = -z[i];
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = -INF;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= min(i, m); j++) {
        if (i > 1) {
          dp[i][j] = dp[i - 1][j];
        }
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x[i - 1] + y[i - 1] + z[i - 1]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (getBit(mask, 0)) {
        x[i] = -x[i];
      }
      if (getBit(mask, 1)) {
        y[i] = -y[i];
      }
      if (getBit(mask, 2)) {
        z[i] = -z[i];
      }
    }

    ans = max(ans, dp[n][m]);
  }

  cout << ans << endl;

  return 0;
}
