#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll h, w, a;
  in2(h, w);
  vector<vector<ll>> c(h, vector<ll>(w));
  vector<ll> s, t, u, v;
  rep(i, h){
    rep(j, w)
      in(c[i][j]);
  }
  rep(i, h){
    rep(j, w - 1){
      if(c[i][j] % 2 == 0){
        continue;
      }
      else{
        c[i][j + 1]++;
        s.pb(i + 1);
        t.pb(j + 1);
        u.pb(i + 1);
        v.pb(j + 2);
      }
    }
  }
  rep(i, h - 1){
    if(c[i][w - 1] % 2 == 1){
      c[i + 1][w - 1]++;
      s.pb(i + 1);
      t.pb(w);
      u.pb(i + 2);
      v.pb(w);
    }
  }
  out(s.size());
  memi;
  rep(i, s.size()){
    out(s[i]);
    hina;
    out(t[i]);
    hina;
    out(u[i]);
    hina;
    out(v[i]);
    memi;
  }
}