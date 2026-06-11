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
  ll ans = 0;
  string s, wox = "";
  cin >> s;
  REP(i, s.size()) {
    if (s[i] != 'x') wox += s[i];
  }
  REP(i, (ll)wox.size() / 2) {
    if (wox[i] != wox[wox.size() - 1 - i]) {
      cout << "-1\n";
      return 0;
    }
  }
  vector<ll> cx(s.size());
  ll t = 0;

  REP(i, s.size() + 1) {
    if (s[i] == 'x')
      cx[t]++;
    else {
      t++;
    }
  }

  REP(i, floor(t / 2)) { ans += abs(cx[i] - cx[t - i - 1]); }
  cout << ans << "\n";
  return 0;
}
