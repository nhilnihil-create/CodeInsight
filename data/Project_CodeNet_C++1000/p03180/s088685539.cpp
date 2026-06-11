#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;

  ll R[N][N];
  ll a;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a;
      R[i][j] = a;
    }
  }

  int L = 1 << N;
  ll SCORE[L];

  for (int mask = 0; mask < L; ++mask) {
    ll s = 0;

    for (int i = 0; i < N; ++i) {
      if (((mask >> i) & 1) == 0) continue;

      for (int j = i + 1; j < N; ++j) {
        if ((mask >> j) & 1) {
          s += R[i][j];
        }
      }
    }

    SCORE[mask] = s;
  }

  ll dp[L];
  memset(dp, 0, sizeof(dp));

  for (int used = 0; used < L; ++used) {
    int unused = used ^ (L - 1);
    int mask = unused;

    while (mask > 0) {
      ll v = dp[used] + SCORE[mask];
      int nmask = mask | used;

      dp[nmask] = max(dp[nmask], v);
      mask = (mask - 1) & unused;
    }
  }

  cout << dp[L - 1] << endl;

  return 0;
}
