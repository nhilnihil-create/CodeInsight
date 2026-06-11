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

  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  rep(i, 0, a) cin >> s[i];
  rep(i, 0, b) cin >> t[i];

  while (q--) {
    ll x;
    cin >> x;
    auto its = lower_bound(s.begin(), s.end(), x);
    auto itt = lower_bound(t.begin(), t.end(), x);
    ll s_right = *its, t_right = *itt;
    if (its == s.end())
      s_right = 1e18;
    if (itt == t.end())
      t_right = 1e18;

    ll s_left, t_left;
    if (its == s.begin())
      s_left = -1e18;
    else {
      its--;
      s_left = *its;
    }

    if (itt == t.begin())
      t_left = -1e18;
    else {
      itt--;
      t_left = *itt;
    }

    ll x1 = x - min(s_left, t_left);
    ll x2 = max(s_right, t_right) - x;
    ll x3 = (x - t_left) + (s_right - t_left);
    ll x4 = (x - s_left) + (t_right - s_left);
    ll x5 = (t_right - x) + (t_right - s_left);
    ll x6 = (s_right - x) + (s_right - t_left);

    cout << min({x1, x2, x3, x4, x5, x6}) << endl;
  }
}
