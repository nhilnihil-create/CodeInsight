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
  ll n, ans = -1;
  string s;
  cin >> n >> s;
  for (ll i = 1; i < n; i++) {
    string x = s.substr(0, i);
    string y = s.substr(i, n - i);
    set<char> st1,st2;
    ll t=0;
    REP(i, x.size()) { st1.insert(x[i]); }
    REP(i, y.size()) {
      if (st1.count(y[i])&&!st2.count(y[i])) t++;
      st2.insert(y[i]);
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
  
  return 0;
}
