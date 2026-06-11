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

  int n;
  cin >> n;
  vector<ll> a(n), acc(n + 1, 0);
  rep(i, 0, n) {
    cin >> a[i];
    acc[i + 1] = acc[i] + a[i];
  }

  map<ll, ll> mp;
  rep(i, 0, n + 1) { mp[acc[i]]++; }

  ll ans = 0;
  for (auto m : mp) {
    if (m.second > 1) {
      ans += m.second * (m.second - 1) / 2;
    }
  }

  cout << ans << endl;
}
