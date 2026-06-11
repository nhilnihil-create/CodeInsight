#include <bits/stdc++.h>

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;
using namespace std;

ll N;
string s,t;

bool f(ll &lx, ll &ux, char inc, char dec, ll W, ll x) {
  char none = 'x';
  string ss, tt;
  ss = s;
  tt = t;
  rep(i,0,ss.size()) {
    if (ss[i] != inc && ss[i] != dec)
      ss[i] = none;
    if (tt[i] != inc && tt[i] != dec)
      tt[i] = none;
  }
  for (int i=N-1; i>=0; i--) {
    if (t[i] == dec) ux = min(ux+(ll)1, W);
    if (t[i] == inc) lx = max(lx-(ll)1, (ll)1);

    if (s[i] == dec) lx++;
    if (s[i] == inc) ux--;

    if (lx > ux)
      return false;

    lx = max(lx, (ll)1);
    ux = min(ux, W);
  }

  if (x < lx || x > ux)
    return false;

  return true;
}

signed main() {
  ll H, W, y, x;
  cin>>H>>W>>N>>y>>x>>s>>t;

  ll lx = 1, ux = W; // 駒が残るための範囲
  ll ly = 1, uy = H;
  bool ok1 = f(lx, ux, 'R', 'L', W, x);
  bool ok2 = f(ly, uy, 'D', 'U', H, y);

  if (!ok1 || !ok2)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;

  //cout<<lx<<"-"<<ux<<endl;
  //cout<<ly<<"-"<<uy<<endl;
  return 0;
}
