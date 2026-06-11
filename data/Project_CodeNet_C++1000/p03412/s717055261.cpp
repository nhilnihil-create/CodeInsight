#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n; cin >> n;
  vll a(n); REP(i, n) cin >> a.at(i);
  vll b(n); REP(i, n) cin >> b.at(i);
  sort(b.begin(), b.end());
  ll k = 1;
  ll ans = 0;
  REP(i, 29) {
    vll ar(n), br(n);
    ll div = (1 << i);
    REP(j, n) {
      ar.at(j) = a.at(j) % (div << 1);
      br.at(j) = b.at(j) % (div << 1);
    }
    sort(br.begin(), br.end());
    ll ians = 0;
    REP(j, n) {
      ians += lower_bound(br.begin(), br.end(), 2*div-ar.at(j)) - lower_bound(br.begin(), br.end(), div-ar.at(j)) +
        lower_bound(br.begin(), br.end(), 4*div-ar.at(j)) - lower_bound(br.begin(), br.end(), 3*div-ar.at(j));
    }
    ans += ((ians%2) << i);
  }
  cout << ans << endl;
  return 0;
}
