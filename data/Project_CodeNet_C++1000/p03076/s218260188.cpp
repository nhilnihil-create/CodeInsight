#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int t, r = 10;
  int ans = 0;
  while(cin >> t) {
    ans += (t / 10) * 10;
    if (t % 10 != 0) {
      ans += 10;
      r = min(r, t % 10);
    }
  }
  if (r < 10) ans -= (10-r);
  cout << ans << endl;
  return 0;
}