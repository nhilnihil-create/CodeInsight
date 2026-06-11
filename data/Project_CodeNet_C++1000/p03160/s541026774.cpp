#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n; cin >> n;
  vi v(n);
  rep(i,0,n) cin >> v[i];

  vi dp(n,0);
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + abs(v[i] - v[i-1]);
    if (i > 1)
      dp[i] = min(dp[i - 2] + abs(v[i] - v[i - 2]), dp[i]);
  }
  cout << dp[n - 1];
}