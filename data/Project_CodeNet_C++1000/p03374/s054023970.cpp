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
  ll n, c;
  cin >> n >> c;
  vl x(n), y(n), u(n), s(n + 1, 0), t(n + 1, 0);
  rep(i, n) {
    cin >> x[i] >> u[i];
    y[i] = c - x[i];
  }
  vl v = u;
  reverse(all(y));
  reverse(all(v));
  rep(i, n) {
    s[i + 1] = s[i] + u[i];
    t[i + 1] = t[i] + v[i];
  }
  rep(i, n) {
    s[i + 1] -= x[i];
    t[i + 1] -= y[i];
  }
  ll ans = 0;
  rep(_, 2) {
    set<ll, greater<ll>> st;
    for(int i = n; i >= 1; i--) {
      st.insert(t[n - i]);
      ans = max(ans, s[i]);
      ll now = s[i] + *st.begin();
      ans = max(ans, now - x[i - 1]);
    }
    swap(s, t);
    swap(x, y);
  }
  cout << ans << endl;
}