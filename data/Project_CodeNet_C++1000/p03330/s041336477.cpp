#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<int>> d(c, vector<int>(c));
  rep(i,c) rep(j,c) cin >> d[i][j];
  vector<int> a(n * n);
  rep(i,n) rep(j,n) cin >> a[i * n + j], a[i * n + j]--;
  vector<vector<int>> dp(3, vector<int>(c, 0));
  
  for (int i = 0; i < n * n; i++) {
    for (int j = 0; j < c; j++) {
      int x = i / n, y = i % n;
      dp[(x + y) % 3][j] += d[a[i]][j];
    }
  }
  int res = INF;
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      if (i == j) continue;
      for (int k = 0; k < c; k++) {
        if (j == k) continue;
        if (i == k) continue;
        res = min(dp[0][i] + dp[1][j] + dp[2][k], res);
      }
    }
  }
  cout << res << endl;
  return 0;
} 