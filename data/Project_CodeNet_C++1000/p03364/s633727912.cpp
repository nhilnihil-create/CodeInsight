#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int n;
char a[N][N], b[N][N];

int shift(int x) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      b[i][j] = a[i][(j + x) % n];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (b[i][j] != b[j][i])
        return 0;
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", a[i]);
  int ans = 0;
  for (int j = 0; j < n; ++j)
    ans += shift(j);
  printf("%d\n", ans * n);
  return 0;
}