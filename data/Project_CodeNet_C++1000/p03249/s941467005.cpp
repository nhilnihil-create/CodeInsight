#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
using namespace std;

const int mod = 1e9 + 7;
typedef long long li;

inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
inline int Mul(int x, int y) { return (int)((li)x * y % mod); }
inline int Mul(int x, int y, int z) { return Mul(x, Mul(y, z)); }

int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}

// ----------------------------------------

const int maxn = 1e5;
const li infl = 1e18;

int n;
li d[maxn];
map<li, int> id;

int fa[maxn];
int size[maxn];
li sdep[maxn];

void No(void) {
  puts("-1");
  exit(0);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", d + i);
    id[d[i]] = i;
    size[i] = 1;
    sdep[i] = 0;
  }
  int root = min_element(d, d + n) - d;
  while (id.size() > 1) {
    int u = (--id.end())->second;
    id.erase(--id.end());
    li fa_d = d[u] - (n - size[u]) + size[u];
    if (!id.count(fa_d)) No();
    fa[u] = id[fa_d];
    // printf("fa[%d] = %d\n", u, fa[u]);
    size[fa[u]] += size[u];
    sdep[fa[u]] += sdep[u] + size[u];
  }
  // printf("root = %d\n", root);
  // printf("%lld %d\n", sdep[root], size[root]);
  if (d[root] != sdep[root]) No();
  for (int i = 0; i < n; ++i) {
    if (i != root) {
      printf("%d %d\n", i + 1, fa[i] + 1);
    }
  }
  return 0;
}
