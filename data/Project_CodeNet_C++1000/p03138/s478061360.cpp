#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<int> cnt(50, 0);

  for (int i = 0; i < n; i++) {
    for (int d = 0; d < 50; d++) {
      if (a[i] & (1LL << d)) {
        cnt[d]++;
      }
    }
  }

  vector<vector<ll>> dp(51, vector<ll>(2, -1));
  dp[50][0] = 0;
  for (int d = 49; d >= 0; d--) {
    ll c0 = (1LL << d) * cnt[d];
    ll c1 = (1LL << d) * (n - cnt[d]);
    if (dp[d + 1][1] != -1) {
      dp[d][1] = max(dp[d][1], dp[d + 1][1] + max(c1, c0)); 
    }
    if (k & (1LL << d)) {
      dp[d][1] = max(dp[d][1], dp[d + 1][0] + c0);
      dp[d][0] = max(dp[d][0], dp[d + 1][0] + c1);
    } else {
      dp[d][0] = max(dp[d][0], dp[d + 1][0] + c0);
    }
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0; 
} 