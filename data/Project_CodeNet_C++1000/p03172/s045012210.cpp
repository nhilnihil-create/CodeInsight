#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
vector<ll> a;
ll dp[110][100010];
ll mod = 1000000007;

int main() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i <= n; ++i) dp[i][0] = 1;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k; ++j)
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mod -
                 (j - a[i - 1] - 1 >= 0 ? dp[i - 1][j - a[i - 1] - 1] : 0),
      dp[i][j] %= mod;
  cout << dp[n][k] << endl;
  return 0;
}