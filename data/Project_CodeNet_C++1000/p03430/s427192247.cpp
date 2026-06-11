/*

solution:
 lps == lcs( s, s')

 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define inf 0x3f3f3f

const int maxn = 333;

char s[maxn];
int f[maxn][maxn][maxn], k, n;

int main() {
  scanf("%s%d", s + 1, &k);
  n = strlen(s + 1);

  for (int i = 1; i <= n; ++i)
    f[i][i][0] = 1;

  for (int l = 1; l <= n; ++l)
    for (int i = 1; i + l <= n; ++i)
      for (int p = 0, j = i + l; p <= k; ++p) {
        f[i][j][p] = max(f[i + 1][j][p], f[i][j - 1][p]);

        if (s[i] == s[j])
          f[i][j][p] = max(f[i][j][p], f[i + 1][j - 1][p] + 2);

        if (p)
          f[i][j][p] = max(f[i][j][p], f[i + 1][j - 1][p - 1] + 2);
      }

  int ans = 0;
  for (int i = 0; i <= k; i++)
    ans = max(ans, f[1][n][i]);

  printf("%d\n", ans);
  return 0;
}
