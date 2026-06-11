#include <bits/stdc++.h>

using namespace std;

const int N = 310;

char s[N];
int f[N][N][N];

int main() {
  int m;
  scanf("%s %d", s + 1, &m);
  int n = (int)strlen(s + 1);
  memset(f, 0, sizeof f);
  for (int i = 1; i <= n; ++i) {
    for (int j = n; j >= i; --j) {
      for (int k = 0; k <= m; ++k) {
        f[i][j][k] = max(f[i][j][k], f[i - 1][j + 1][k] + 2 * (s[i] == s[j]) - (j == i));
        f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
        f[i][j][k] = max(f[i][j][k], f[i][j + 1][k]);
      }
      for (int k = 1; k <= m; ++k) {
        f[i][j][k] = max(f[i][j][k], f[i - 1][j + 1][k - 1] + 2 - (j == i));
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      for (int k = 0; k <= m; ++k) {
        ans = max(ans, f[i][j][k]);
      }
    }
  }
  printf("%d\n", ans);
}
