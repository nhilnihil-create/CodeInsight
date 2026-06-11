#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (a%b == 0) return b;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
  ll n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  ll l = lcm(n,m);
  ll ln = l / n, lm = l / m;
  ll lnm = lcm(ln,lm);
  ll ans = l;
  for (ll i = 0; i<l; i+=lnm) {
    if (s[i/ln] != t[i/lm]) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}