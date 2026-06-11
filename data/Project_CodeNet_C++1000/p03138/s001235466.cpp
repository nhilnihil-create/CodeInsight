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
  ll k;
  cin >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  
  vector<vector<ll>> dp(60, vector<ll>(2, -1));
  dp[59][0] = 0;
  for (int d = 58; d >= 0; d--) {
    ll cnt1 = 0, cnt0 = 0;

    for (int i = 0; i < n; i++) {
      if (a[i] & (1LL << d)) cnt1++;
      else cnt0++;
    }

    ll cost1 = cnt0 * (1LL << d);
    ll cost0 = cnt1 * (1LL << d);

    if (dp[d + 1][1] != -1) {
      dp[d][1] = max(dp[d][1], dp[d + 1][1] + max(cost0, cost1));
    }
    if (k & (1LL << d)) {
      dp[d][0] = max(dp[d][0], dp[d + 1][0] + cost1);
      dp[d][1] = max(dp[d][1], dp[d + 1][0] + cost0);
    } else {
      dp[d][0] = max(dp[d][0], dp[d + 1][0] + cost0);
    }
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
} 