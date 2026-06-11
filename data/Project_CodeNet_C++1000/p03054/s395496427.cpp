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
  ll h, w, n; cin >> h >> w >> n;
  ll sr, sc; cin >> sr >> sc;
  string s, t; cin >> s >> t;

  ll d=0, u=h+1;
  bool is_fall = false;
  for (ll i=n-1; i>=0; i--) {
    if (t.at(i) == 'U' && u<=h) u++;
    else if (t.at(i) == 'D' && d>=1) d--;
    if (s.at(i) == 'U') d++;
    else if (s.at(i) == 'D') u--;
    if (d >= u-1) is_fall = true;
  }
  if (d >= sr || u <= sr) is_fall = true;

  ll l=0, r=w+1;
  for (ll i=n-1; i>=0; i--) {
    if (t.at(i) == 'L' && r<=w) r++;
    else if (t.at(i) == 'R' && l>=1) l--;
    if (s.at(i) == 'L') l++;
    else if (s.at(i) == 'R') r--;
    if (l >= r-1) is_fall = true;
  }
  if (l >= sc || r <= sc) is_fall = true;

  if (is_fall) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
