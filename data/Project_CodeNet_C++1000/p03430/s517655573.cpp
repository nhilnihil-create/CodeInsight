#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 300 + 10;

char s[MAXN];
int k, n;
inline void chmax(int &x, int y) {
  x = std::max(x, y);
}
namespace solver1 {
  int f[MAXN][MAXN][MAXN];
  void main() {
    for (int i = 1; i <= n; i++) {
      for (int j = n; j > i; j--) {
        for (int t = k; t >= 0; t--) {
          if (s[i] == s[j]) f[i][j][t] = f[i - 1][j + 1][t] + 1;
          chmax(f[i][j][t], f[i - 1][j][t]);
          chmax(f[i][j][t], f[i][j + 1][t]);
          if (t == k) continue;
          //chmax(f[i][j][t], f[i][j][t + 1]);
          chmax(f[i][j][t], f[i - 1][j + 1][t + 1] + 1);
          if (t + 1 == k) continue;
          //chmax(f[i][j][t], f[i - 1][j + 1][t + 2] + 1);
          
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        chmax(ans, f[i][i + 1][j] * 2);
        chmax(ans, f[i][i + 2][j] * 2 + 1);
      }
    }
    printf("%d\n", ans);
  }
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &k);
  solver1::main();
}
