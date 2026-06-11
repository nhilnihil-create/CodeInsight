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

  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  if (s[0] != t[0]) {
    cout << -1 << endl;
    return 0;
  }

  ll lcmv = n / __gcd(n, m) * m;
  int a = lcmv / n, b = lcmv / m;

  map<ll, char> mp;
  ll tt = a;
  rep(i, 1, n) {
    mp[tt] = s[i];
    tt += a;
  }

  tt = b;
  rep(i, 1, m) {
    if (mp.count(tt)) {
      if (mp[tt] != t[i]) {
        cout << -1 << endl;
        return 0;
      }
    }
    tt += b;
  }

  cout << lcmv << endl;
}
