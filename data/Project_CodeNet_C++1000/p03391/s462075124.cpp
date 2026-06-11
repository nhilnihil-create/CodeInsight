#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long li;

int n;

int main(void) {
  scanf("%d", &n);
  li ans = 0, diff = 0;
  int tmp = 2e9;
  for (int i = 1, x, y; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    diff += abs(x - y);
    ans += x;
    if (y < x) tmp = min(tmp, y);
  }
  if (diff) printf("%lld\n", ans - tmp);
  else puts("0");

  return 0;
}
