#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n), y(n), h(n);
  ll inot0;
  REP(i, n) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] != 0) inot0 = i;
  }

  REP(cx, 101) {
    REP(cy, 101) {
      ll h_pre = h[inot0] + abs(x[inot0] - cx) + abs(y[inot0] - cy);
      bool f = true;
      REP(i, n) {
        if (h[i] != max(0ll, h_pre - abs(x[i] - cx) - abs(y[i] - cy)))
          f = false;
      }
      if (f) {
        cout << cx << ' ' << cy << ' ' << h_pre << endl;
        return 0;
      }
    }
  }

  return 0;
}
