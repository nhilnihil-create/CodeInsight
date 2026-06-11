#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  int a[501][501] = {}, o[100001] = {};
  for(int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    a[l][r]++;
  }
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < n; j++) a[i][j + 1] += a[i][j];
  for(int i = 0; i < q; i++) {
    int P, Q;
    scanf("%d %d", &P, &Q);
    for(int j = P; j <= Q; j++) o[i] += a[j][Q] - a[j][P - 1];
  }
  for(int i = 0; i < q; i++) printf("%d\n", o[i]);
}