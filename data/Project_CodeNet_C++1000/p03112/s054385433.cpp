#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

const ll INF = 1000000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, q;
  cin >> a >> b >> q;

  vector<ll> s(a + 2), t(b + 2);
  s[0] = t[0] = -INF;
  s[a + 1] = t[b + 1] = INF;

  rep(i, 1, a + 1) cin >> s[i];
  rep(i, 1, b + 1) cin >> t[i];

  while (q--) {
    ll x;
    cin >> x;
    int si = lower_bound(s.begin(), s.end(), x) - s.begin();
    int ti = lower_bound(t.begin(), t.end(), x) - t.begin();
    ll sl = s[si - 1], sr = s[si], tl = t[ti - 1], tr = t[ti];

    ll a1 = max(sr, tr) - x, a2 = x - min(sl, tl);
    ll a3 = (sr - x) + (sr - tl), a4 = (tr - x) + (tr - sl);
    ll a5 = (x - sl) + (tr - sl), a6 = (x - tl) + (sr - tl);

    cout << min({a1, a2, a3, a4, a5, a6}) << endl;
  }
}
