#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (floor((n - 1) / 2.0) + 1 >= k) puts("YES");
  else puts("NO");
}
