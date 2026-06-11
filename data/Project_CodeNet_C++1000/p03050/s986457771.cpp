#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i * i != n)
        res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  vector<ll> div = divisor(n);
  int divn = div.size();

  ll ans = 0;
  rep(i, 1, divn) {
    ll d = div[i] - 1;
    ll a = n / d;
    ll b = n % d;
    if (a==b)
      ans += div[i] - 1;
  }

  cout << ans << endl;
}
