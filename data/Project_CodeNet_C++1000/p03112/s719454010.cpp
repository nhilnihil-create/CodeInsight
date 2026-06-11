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

void f(set<ll> &s, ll &sl, ll &sr, ll x){
  sl = -1e18, sr = 1e18;
  auto sitr = s.lower_bound(x);
  if(sitr != s.end()) sr = *sitr;
  if(sitr != s.begin()){
    sitr--;
    sl = *sitr;
  }
}

ll ff(ll x, ll s, ll t){
  return min(abs(x-s), abs(x-t)) + abs(s-t);
}

ll fc(set<ll> &s, set<ll> &t, ll x){
  ll sl = -1e18, sr = 1e18, tl = -1e18, tr = 1e18;
  f(s, sl, sr, x);
  f(t, tl, tr, x);
  return min({ff(x, sl, tl), ff(x, sl, tr), ff(x, sr, tl), ff(x, sr, tr)});
}

int main(){
  int a, b, qe;
  cin >> a >> b >> qe;
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
  rep(_q, qe){
    ll x;
    cin >> x;
    cout << fc(s, t, x) << endl;
  }
  return 0;
}