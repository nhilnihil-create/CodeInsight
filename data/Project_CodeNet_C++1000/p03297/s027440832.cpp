#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes() {
  cout << "Yes" << endl;
  return;
}

void no() {
  cout << "No" << endl;
  return;
}

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a < b || d < b) {
    no();
    return;
  }
  if (c >= b - 1) {
    yes();
    return;
  }
  ll g = gcd(b, d);
  ll r = (a - b + 1) % g;
  if (r == 0 || r + b - c - 2 >= g) {
    no();
    return;
  }
  yes();
}

int main() {
  ll t;
  cin >> t;
  while (t--) solve();
}