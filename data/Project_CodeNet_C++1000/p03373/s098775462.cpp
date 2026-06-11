#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  c *= 2;
  int ans = 0;
  if (c < a + b) {
    int t = min(x, y);
    ans += t * c;
    x -= t;
    y -= t;
    if (x > 0)
      ans += min(a, c) * x;
    if (y > 0)
      ans += min(b, c) * y;
  } else {
    ans = a * x + b * y;
  }
  printf("%d\n", ans);
  return 0;
}