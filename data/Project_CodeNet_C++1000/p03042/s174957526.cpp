// 2020-07-04 16:59:27
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  auto isYY = [](string s) {
    return "00" <= s && s <= "99";
  };
  auto isMM = [](string s) {
    return "01" <= s && s <= "12";
  };
  auto isYYMM = [&](string s) {
    return isYY(s.substr(0, 2)) && isMM(s.substr(2, 2));
  };
  auto isMMYY = [&](string s) {
    return isMM(s.substr(0, 2)) && isYY(s.substr(2, 2));
  };
  string s;
  cin >> s;
  bool yymm = isYYMM(s);
  bool mmyy = isMMYY(s);
  string ans = "";
  if(yymm && mmyy) ans = "AMBIGUOUS";
  else if(!yymm && !mmyy) ans = "NA";
  else if(yymm && !mmyy) ans = "YYMM";
  else if(!yymm && mmyy) ans = "MMYY";
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}