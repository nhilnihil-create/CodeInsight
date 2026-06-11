#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w, d, q;
  cin >> h >> w >> d;
  map<int, P> mp;
  rep(i, 0, h) rep(j, 0, w) {
    int a;
    cin >> a;
    mp[a] = make_pair(i + 1, j + 1);
  }

  vector<ll> dp(h * w + 1);
  rep(i, 1, h * w + 1) {
    if (i <= d)
      continue;
    dp[i] = dp[i - d] + abs(mp[i].first - mp[i - d].first) +
            abs(mp[i].second - mp[i - d].second);
  }

  cin >> q;
  map<P, int> mpans;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l] << endl;
  }
}
