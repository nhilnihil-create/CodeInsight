#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  int a[501][501] = {};
  for(int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    a[l][r]++;
  }
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < n; j++) a[i][j + 1] += a[i][j];
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < n; j++) a[j + 1][i] += a[j][i];
  for(int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", a[r][r] - a[r][l - 1] - a[l - 1][r] + a[l - 1][l - 1]);
  }
}