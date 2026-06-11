#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0, mn = 2e9;
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ans += b;
    if (a > b)
      mn = min(mn, 1LL * b), ok = true;
  }
  printf("%lld\n", (ok ? ans - mn : 0));
  return 0;
}