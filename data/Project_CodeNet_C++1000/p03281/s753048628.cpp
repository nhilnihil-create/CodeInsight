#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

map<ll, int> prime_factor(ll n) {
  map<ll, int> ret;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    map<ll, int> mp = prime_factor(i);
    int c = 1;
    for (auto m : mp)
      c *= m.second + 1;
    if (c == 8)
      ans++;
  }

  cout << ans << endl;
}
