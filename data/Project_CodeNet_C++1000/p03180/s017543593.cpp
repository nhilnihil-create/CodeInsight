#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i,n) rep(j,n) cin >> a[i][j];
  
  vector<ll> d(1 << n, 0);

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) continue;
      for (int k = 0; k < n; k++) if (i & (1 << k)) d[i] += a[j][k];
    }
    d[i] /= 2;
  }

  vector<ll> dp(1 << n, 0);

  for (int bit = 0; bit < (1 << n); bit++) {
    for (int i = bit; i >= 0; i--) {
      i &= bit;
      dp[bit] = max(dp[bit], d[i] + dp[bit - i]);
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  return 0;
} 