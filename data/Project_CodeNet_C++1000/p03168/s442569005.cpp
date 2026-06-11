#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 3e3 + 10;

double f[2][maxN][maxN];
double p[maxN];
int n;

int main(){
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  f[1][0][1] = 1 - p[1]; f[1][1][0] = p[1];
  for (int i = 2; i <= n; ++i) {
    int stt = i & 1, op = 1 ^ stt;
    for (int j = 0; j <= i; ++j) {
      int k = i - j;
      if (j > 0) f[stt][j][k] = (f[stt][j][k] + f[op][j-1][k] * p[i]);
      if (k > 0) f[stt][j][k] = (f[stt][j][k] + f[op][j][k-1] * (1-p[i]));
    }
    for (int j = 0; j <= i - 1; ++j) {
      f[op][j][i-j] = 0;
    }
  }
  double ans = 0;
  for (int j = (n - 1) / 2 + 1; j <= n; ++j) {
    ans = ans + f[n % 2][j][n-j];
  }
  cout << fixed << setprecision(10) << ans;
return 0;
}
