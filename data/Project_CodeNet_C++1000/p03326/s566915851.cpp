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

  int n, m;
  cin >> n >> m;
  vector<vector<ll>> v(n, vector<ll>(3));
  rep(i, 0, n) cin >> v[i][0] >> v[i][1] >> v[i][2];

  ll ans = 0;
  rep(i, 0, 1 << 3) {
    vector<ll> x(n);
    rep(k, 0, n) {
      rep(j, 0, 3) {
        if (i >> j & 1)
          x[k] += v[k][j];
        else
          x[k] -= v[k][j];
      }
    }

    sort(x.rbegin(), x.rend());
    ll c = 0;
    rep(j, 0, m) c += x[j];
    chmax(ans, c);
  }

  cout << ans << endl;
}
