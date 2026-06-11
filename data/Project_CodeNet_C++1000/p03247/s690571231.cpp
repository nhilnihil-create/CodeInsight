#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
using namespace std;

typedef long long li;

// const int mod = 1e9 + 7, inv2 = mod + 1 >> 1;
// inline int Add(int x) { return x >= mod ? x - mod : x; }
// inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
// inline int Sub(int x) { return x < 0 ? x + mod : x; }
// inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
// inline int Mul(int x, int y) { return (li)x * y % mod; }

// int Pow(int x, int y) {
//   int z = 1;
//   for (; y; y >>= 1) {
//     if (y & 1) z = Mul(z, x);
//     x = Mul(x, x);
//   }
//   return z;
// }

// ----------------------------------------

const int maxn = 1000;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const char dc[] = "LURD";
const li infl = 1e18;

int n;
int x[maxn], y[maxn];
int m;
int d[maxn];

void Solve(li X, li Y) {
  for (int i = 0; i < m; ++i) {
    li X2, Y2, val = infl;
    char chosen;
    for (int t = 0; t < 4; ++t) {
      li x = X - dx[t] * d[i];
      li y = Y - dy[t] * d[i];
      li v = abs(x) + abs(y);
      if (v < val) {
        val = v;
        X2 = x;
        Y2 = y;
        chosen = dc[t];
      }
    }
    X = X2;
    Y = Y2;
    putchar(chosen);
  }
  putchar('\n');
}

int main(void) {
  scanf("%d", &n);
  bool odd = false, even = false;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
    if (x[i] + y[i] & 1) {
      odd = true;
    } else {
      even = true;
    }
  }
  if (odd && even) {
    puts("-1");
    return 0;
  }

  if (even) d[m++] = 1;
  for (int i = 0; i <= 30; ++i) {
    d[m++] = 1 << i;
  }
  reverse(d, d + m);
  printf("%d\n", m);
  for (int i = 0; i < m; ++i) {
    printf("%d%c", d[i], " \n"[i == m - 1]);
  }

  for (int i = 0; i < n; ++i) {
    Solve(x[i], y[i]);
  }
  return 0;
}
