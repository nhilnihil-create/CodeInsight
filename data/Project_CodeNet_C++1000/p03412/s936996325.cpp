#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long li;

const int maxn = 2e5 + 10, maxlgn = 29;
int n, a[maxn], b[maxn], c[maxn];

int Solve(int x, int lower, int upper) {
  return lower_bound(c + 1, c + 1 + n, upper - x) -
    lower_bound(c + 1, c + 1 + n, lower - x);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  for (int i = 1; i <= n; ++i)
    scanf("%d", b + i);

  int ans = 0;
  for (int l = 0; l < maxlgn; ++l) {
    int tmp = (1 << l), cnt = 0;
    for (int i = 1; i <= n; ++i) c[i] = b[i] % (tmp << 1);
    sort(c + 1, c + 1 + n);
    for (int i = 1, x; i <= n; ++i) {
      x = a[i] % (tmp << 1);
      cnt += Solve(x, tmp * 1, tmp * 2) % 2;
      cnt += Solve(x, tmp * 3, tmp * 4) % 2;
    }
    if (cnt & 1) ans |= (1 << l);
  }
  printf("%d\n", ans);

  return 0;
}
