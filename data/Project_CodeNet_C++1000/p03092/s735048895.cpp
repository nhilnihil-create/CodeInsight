#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
using namespace std;

// const int mod = 1e9 + 7;
// inline int Add(int x) { return x >= mod ? x - mod : x; }
// inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
// inline int Sub(int x) { return x < 0 ? x + mod : x; }
// inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
// inline int Mul(int x, int y) { return (int)((li)x * y % mod); }

// int Pow(int x, int y) {
//   int z = 1;
//   for (; y; y >>= 1) {
//     if (y & 1) z = Mul(z, x);
//     x = Mul(x, x);
//   }
//   return z;
// }

// ----------------------------------------

typedef long long li;
const int maxn = 5000;
const li inf = 1e18;
int n, A, B;
int p[maxn];
li dp[maxn + 1], dp2[maxn + 1];

void Min(li &a, li b) {
  if (b < a) a = b;
}

int main(void) {
  scanf("%d%d%d", &n, &A, &B);
  swap(A, B);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i), --p[i];
  }
  FILL(dp, n + 1, 0);

  for (int i = 0; i < n; ++i) {
    FILL(dp2, n + 1, 0x3f);
    for (int j = 0; j <= n; ++j) {
      if (j < n) Min(dp[j + 1], dp[j]);
      if (j == p[i]) {
        Min(dp2[j + 1], dp[j]);
      } else if (j < p[i]) {
        Min(dp2[j], dp[j] + B);
      } else {
        Min(dp2[j], dp[j] + A);
      }
    }
    COPY(dp2, n + 1, dp);
    // for (int j = 0; j <= n; ++j) {
    //   printf("dp[%d][%d] = %lld\n", i + 1, j, dp[j]);
    // }
  }
  for (int j = 0; j < n; ++j) {
    Min(dp[j + 1], dp[j]);
  }

  li ans = dp[n];
  printf("%lld\n", ans);
  return 0;
}
