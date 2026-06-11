#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  ll ans = lcm(n, m);
  ll g = gcd(n, m);
  ll np = n / g;
  ll mp = m / g;

  rep(i, g) if (s[np * i] != t[mp * i]) ans = -1;
  cout << ans << endl;

  return 0;
}