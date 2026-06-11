#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e3 + 10;
const int mod = 1e9 + 7;

int n, m;
char a[maxN][maxN];
int dx[] = {-1, 0};
int dy[] = {0, -1};
int dp[maxN][maxN];

int main(){
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= m; ++j) {
    cin >> a[i][j];
  }
  dp[1][1] = 1;
  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= m; ++j) {
    if (a[i][j] == '#') continue;
    for (int id = 0; id < 2; ++id) {
      int u = i + dx[id], v = j + dy[id];
      if (u > 0 && v > 0)
        dp[i][j] = (0ll + dp[i][j] + dp[u][v]) % mod;
    }
  }
  cout << dp[n][m];
return 0;
}
