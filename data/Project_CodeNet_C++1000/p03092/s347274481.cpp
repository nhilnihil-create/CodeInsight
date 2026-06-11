#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 5005;
int n, a, b;
int p[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &a, &b) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

long long dp[maxn][maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    dp[0][i] = 0;
    dp[i][0] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int mx = -1;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (p[j] < i) {
        if (mx == -1 || p[j] > p[mx]) {
          mx = j;
          cnt = 0;
        } else {
          cnt++;
        }
      }
      auto &cur = dp[i][j + 1];
      if (mx == -1) {
        cur = 0;
        continue;
      }
      if (cnt == 0) {
        cur = dp[i][mx];
        continue;
      }
      cur = a + dp[p[mx]][j + 1];
      cur = min(cur, dp[i][mx] + (long long) b * cnt);
    }
  }
  printf("%lld\n", dp[n][n]);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
