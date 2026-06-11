#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<P>> g(n);
  rep(i, m) {
    ll p, y;
    cin >> p >> y;
    p--;
    g[p].push_back({y, i});
  }
  vector<P> ans(m);
  rep(i, n) {
    sort(all(g[i]));
    rep(x, g[i].size()) {
      ll in = g[i][x].second;
      ans[in] = {i, x};
    }
  }
  rep(i, m) printf("%06d%06d\n", ans[i].first + 1, ans[i].second + 1);
}