#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void fc(const set<ll> &s, const set<ll> &t, ll x){
  auto sr = s.lower_bound(x);
  auto sl = sr;
  sl--;
  auto tr = t.lower_bound(x);
  auto tl = tr;
  tl--;

  ll ans;
  ll a1 = abs(*sr - *tr) + min(abs(x-*sr), abs(x-*tr));
  ll a2 = abs(*sl - *tr) + min(abs(x-*sl), abs(x-*tr));
  ll a3 = abs(*sr - *tl) + min(abs(x-*sr), abs(x-*tl));
  ll a4 = abs(*sl - *tl) + min(abs(x-*sl), abs(x-*tl));
  ans = min({a1, a2, a3, a4});
  cout << ans << endl;
}

int main(){
  int a, b, q;
  cin >> a >> b >> q;
  set<ll> s, t;
  rep(i, a){
    ll in;
    cin >> in;
    s.insert(in);
  }
  rep(i, b){
    ll in;
    cin >> in;
    t.insert(in);
  }
  s.insert(1e15); s.insert(-1e15);
  t.insert(1e15); t.insert(-1e15);
  vector<ll> xx(q);
  rep(i, q) cin >> xx.at(i);
  for(ll x : xx){
    fc(s, t, x);
  }
  return 0;
}