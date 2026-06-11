#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, c, k; cin >> a >> b >> c >> k;
  ll ans = 0;
  if (k%2) ans = b - a;
  else ans = a - b;
  cout << ans << endl;
  return 0;
}