#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[100'009];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int ans = -1;
  int best = 2'000'000'000;
  for (int i = 0; i < n - 1; ++i) {
    int cur = min(abs(a[i] - a[n - 1] / 2), abs(a[i] - (a[n - 1] + 1) / 2));
    if (cur < best) {
      ans = i;
      best = cur;
    }
  }
  printf("%d %d\n", a[n - 1], a[ans]);
}
