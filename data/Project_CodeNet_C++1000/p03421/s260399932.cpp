#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int ans[300'009];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if (a + b - 1 > n || n > (long long)a * b) {
    puts("-1");
    return 0;
  }
  int w = 0;
  if (b > a) {
    swap(a, b);
    w = 1;
  }
  for (int i = 0; i < n; i += a) {
    int j = min(i + a - 1, n - 1);
    for (int k = j; k >= i; --k) {
      ans[i + j - k] = w == 0 ? n - k : k + 1;
    }
  }
  for (int i = n / a * a; i >= 0; i -= a) {
    int rem = n - i;
    if (i / a + rem >= b) {
      int need = b - i / a;
      int extra = rem - need + 1;
      sort(ans + i, ans + n);
      if (w == 0) {
        reverse(ans + i, ans + n);
      }
      for (int j = 0; j < extra / 2; ++j) {
        swap(ans[i + j], ans[i + extra - 1 - j]);
      }
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  putchar('\n');
}
