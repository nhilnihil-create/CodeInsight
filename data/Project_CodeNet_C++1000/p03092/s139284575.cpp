#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int n, a, b, p[N];
long long f[N][N];

int main(void) {
  scanf("%d%d%d", &n, &a, &b);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0, t; j <= n; j++) {
      if(p[i] > j) {
	f[i][p[i]] = min(f[i][p[i]], f[i - 1][j]);
	f[i][j] = min(f[i][j], f[i - 1][j] + a);
      } else {
	f[i][j] = min(f[i][j], f[i - 1][j] + b);
      }
    }
  }
  long long ans = f[0][1];
  for(int i = 0; i <= n; i++) {
    ans = min(ans, f[n][i]);
  }
  cout << ans << endl;
  return 0;
}
