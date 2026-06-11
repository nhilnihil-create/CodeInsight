#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c, d[30][30], m[3][30] = {};
  scanf("%d %d", &n, &c);
  for(int i = 0; i < c; i++)
    for(int j = 0; j < c; j++) scanf("%d", &d[i][j]);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int a;
      scanf("%d", &a);
      m[(i + j) % 3][a - 1]++;
    }
  }
  int o = 1001001001;
  for(int i = 0; i < c; i++) {
    for(int j = 0; j < c; j++) {
      for(int k = 0; k < c; k++) {
        if(i == j || j == k || k == i) continue;
        int t = 0;
        for(int l = 0; l < c; l++) {
          t += d[l][i] * m[0][l];
          t += d[l][j] * m[1][l];
          t += d[l][k] * m[2][l];
        }
        o = min(o, t);
      }
    }
  }
  printf("%d\n", o);
}