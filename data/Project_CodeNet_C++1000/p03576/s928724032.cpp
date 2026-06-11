#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  ll n, k;
  cin >> n >> k;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));
  ll ans = 4e18;
  rep(m, n - k + 1) {
    rep2(i, k, n - m + 1) {
      vector<P> q;
      rep(j, i) q.push_back(P(p[j + m].second, p[j + m].first));
      sort(all(q));
      rep(j, i - k + 1) {
        ll dy = q[j + k - 1].first - q[j].first;
        ll a = 4e18, c = -4e18;
        rep2(x, j, j + k) {
          a = min(a, q[x].second);
          c = max(c, q[x].second);
        }
        ans = min(ans, dy * (c - a));
      }
    }
  }
  cout << ans << endl;
}