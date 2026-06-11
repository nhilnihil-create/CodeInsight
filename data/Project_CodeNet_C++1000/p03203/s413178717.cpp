#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  vector<int> mins(n, m);
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    mins[x] = min(mins[x], y);
  }
  int right = 0;
  for (int i = 1; i < n; ++i) {
    if (right >= mins[i]) {
      printf("%d\n", i);
      return 0;
    }
    if (right + 1 < mins[i]) {
      ++right;
    }
  }
  printf("%d\n", n);
  return 0;
}