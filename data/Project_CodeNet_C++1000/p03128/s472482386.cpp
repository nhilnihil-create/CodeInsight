#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  int cost[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<int> dp(n+1, -1);
  dp[0] = 0;
  FOR(i, 1, n+1) {
    rep(j, m) {
      if (i-cost[a[j]-1] < 0) continue;
      dp[i] = max(dp[i], dp[i-cost[a[j]-1]]+1);
    }
  }
  int k = n;
  rep(i, dp[n]) {
    rep(j, m) {
      if (k-cost[a[j]-1] < 0) continue;
      if (dp[k] == dp[k-cost[a[j]-1]]+1) {
        cout << a[j];
        k -= cost[a[j]-1];
        break;
      }
    }
  }
  cout << endl;
}