#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll g = gcd(n, m);
  ll nn = n / g, mm = m / g;
  ll ans = m / g * n;
  for (ll i = 0; i < g; i++) {
    if (s[i * nn] != t[i * mm]) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
