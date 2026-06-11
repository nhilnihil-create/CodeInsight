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
ll n;
vector<ll> x, y, h;

int main() {
  ll n;
  cin >> n;
  bool all0 = true;
  set<ll> x0, y0;
  ll inot0;
  REP(i, n) {
    ll tx, ty, th;
    cin >> tx >> ty >> th;
    x.push_back(tx);
    y.push_back(ty);
    h.push_back(th);
    if (th == 0) {
      x0.insert(tx);
      y0.insert(ty);
    }
    if (th != 0) {
      all0 = false;
      inot0 = i;
    }
  }

  if (all0) {
    REP(i, 101) {
      REP(j, 101) {
        if (!x0.count(i) && !y0.count(j)) {
          cout << i << j << 1 << endl;
        }
      }
    }
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
      }
    }
  }

  return 0;
}
