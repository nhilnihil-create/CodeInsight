#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, z, w;
  scanf("%d %d %d", &n, &z, &w);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (n == 1) {
    printf("%d\n", abs(a[0] - w));
    return 0;
  }
  printf("%d\n", max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1])));
  return 0;
}

