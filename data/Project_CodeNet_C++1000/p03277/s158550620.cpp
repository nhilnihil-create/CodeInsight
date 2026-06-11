#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

int n, m;
int a[N], s[N], p[N], fw[N * 2];

void ch(int k) {
  for (; k <= m; k += k & -k) ++fw[k];
}

int qr(int k) {
  int ret = 0;
  for (; k; k &= k - 1) ret += fw[k];
  return ret;
}

ll pred(int x) {
  for (int i = 1; i <= n; ++i)
    p[i] = p[i - 1] + (a[i] <= x ? -1 : 1);
  m = n * 2 + 1;
  // p[i] < p[j] ? -1 : 1;
  ll ret = 0;
  memset(fw, 0, sizeof(fw));
  for (int i = 0; i <= n; ++i) {
    int v = p[i] + n + 1;
    ret += 2 * qr(v) - i;
    ch(v);
  }
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  memcpy(s, a, sizeof(a));
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(s + 1, s + n + 1, a[i]) - s;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pred(mid) < 0)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", s[l]);

  return 0;
}
