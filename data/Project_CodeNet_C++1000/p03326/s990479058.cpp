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
  vector<vector<ll>> a(n, vector<ll>(3));
  rep(i, 0, n) { cin >> a[i][0] >> a[i][1] >> a[i][2]; }

  ll ans = 0;
  rep(i, 0, 8) {
    vector<ll> v;
    rep(j, 0, n) {
      ll s = 0;
      rep(k, 0, 3) {
        if ((i / (1 << k)) % 2 == 0) {
          s += a[j][k];
        } else {
          s -= a[j][k];
        }
      }
      v.push_back(s);
    }
    sort(v.rbegin(), v.rend());
    ll t = 0;
    rep(j, 0, m) t += v[j];
    chmax(ans, t);
  }
  cout << ans << endl;
}
