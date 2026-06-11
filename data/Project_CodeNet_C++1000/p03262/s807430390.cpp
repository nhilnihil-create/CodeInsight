#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll n, X;
  cin >> n >> X;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  sort(x.begin(), x.end());
  if (n == 1) {
    cout << abs(X - x[0]) << endl;
    return 0;
  }
  ll ans = abs(x[0] - x[1]), ans2=0;
  rep(i, n - 3) ans = gcd(ans, abs(x[i + 1] - x[i + 2]));
  rep(i, n) ans2 = max(ans2, gcd(ans, X - x[i]));
  cout << ans2 << endl;
  return 0;
}
