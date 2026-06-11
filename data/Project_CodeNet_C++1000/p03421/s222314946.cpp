#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  vvll ab(a, vll());
  if (a+b-1>n || a*b<n) cout << -1 << endl;
  else {
    ll i = 1;
    while (n - i*b > a-i) {
      for (ll j=i*b; j>(i-1)*b; j--) ab.at(i-1).push_back(j);
      i++;
    }
    for (ll j=n-(a-i); j>(i-1)*b; j--) ab.at(i-1).push_back(j);
    i++;
    for (ll j=n-(a-i); j<=n; j++, i++) ab.at(i-1).push_back(j);
  }
  REP(i, a) {
    REP(j, ab.at(i).size()) {
      cout << ab.at(i).at(j);
      if (i != a-1 || j != ab.at(i).size()-1) cout << ' ';
    }
  }
  return 0;
}
