#include <bits/stdc++.h>
using namespace std;

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define mst(x, a) memset(x, a, sizeof(x))

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int INF = 1 << 27;
const ll LLINF = (ll)1 << 60;
const ll MOD = 1e9+7;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  int N;
  scanf("%d", &N);
  vector<vector<int>> a(N, vector<int>(N));
  f(i, 0, N) {
    f(j, 0, N) {
      scanf("%d", &a[i][j]);
    }
  }

  int size = 1 << N;
  // dp[mask]: max score only consider these rabbits
  vector<ll> dp(size, 0);
  dp[0] = 0;
  for (int mask = 1; mask < size; mask++) {
    if (mask >= (1 << (N - 1))) mask = (1 << N) - 1;
    // find first ungrouped rabbit, and decide who group with it;
    int i = N - 1;
    while ((mask & (1 << i)) == 0) {
      i--;
    }
    int remain = mask ^ (1 << i);
    // enumerate subset
    int sub = remain;
    do {
      ll acc = 0;
      for (int j = 0; j < i; j++) {
        if (sub & (1 << j)) {
          acc += a[i][j];
          for (int k = 0; k < j; k++) {
            if (sub & (1 << k)) {
              acc += a[k][j];
            }
          }
        }
      }
      dp[mask] = max(dp[mask], acc + dp[remain ^ sub]);
      sub = (sub - 1) & remain;
    } while (sub != remain);
  }

  printf("%lld\n", dp[size - 1]);
}
