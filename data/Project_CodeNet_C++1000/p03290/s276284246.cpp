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

  int n, g;
  cin >> n >> g;
  vector<P> v(n);
  rep(i, 0, n) {
    int p, c;
    cin >> p >> c;
    v[i] = make_pair(p, c);
  }
  ll a = 0;
  int t = g;
  vector<pair<ll, int>> memo;
  // 大きいほうから貪欲に使うパターンをメモする
  repr(i, 0, n) {
    rep(j, 0, v[i].first) { memo.emplace_back((i + 1) * 100, i); }
    memo[memo.size() - 1].first += v[i].second;
  }

  ll ans = 1e18;
  rep(i, 0, 1 << n) {
    ll cost = 0, count = 0;
    vector<bool> is_use(n, true);
    rep(j, 0, n) {
      // iのjビット目が1なら
      if (i >> j & 1) {
        cost += 100 * (j + 1) * v[j].first + v[j].second;
        count += v[j].first;
        is_use[j] = false;
      }
    }
    if (cost < g) {
      int c = 0, cc = 0;
      while (true) {
        if (!is_use[memo[cc].second]) {
          cc++;
          continue;
        }
        if (cost + memo[cc].first >= g)
          break;
        cost += memo[cc].first;
        c++;
        cc++;
      }
      count += c + 1;
    }
    chmin(ans, count);
  }

  cout << ans << endl;
}
