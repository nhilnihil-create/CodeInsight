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
  ll n, a, k, s, u;
  in(n);
  vector<ll> c(n);
  rep(i, n)
    in(c[i]);
  vector<vector<ll>> d(n, vector<ll> (0));
  rep(i, n){
    bitset<20> t(c[i]);
    rep(j, 20){
      if(t.test(j))
        d[i].pb(j);
    }
  }
  vector<bool> h(20, false), g(20);
  s = 0;
  u = 0;
  k = 0;
  rep(i, n){
    k = 0;
    while(u < n){
      rep(l, 20)
        g[l] = h[l];
      rep(j, d[u].size()){
        if(!g[d[u][j]])
          g[d[u][j]] = true;
        else
          k = 1;
      }
      if(k)
        break;
      u++;
      rep(l, 20)
        h[l] = g[l];
    }
    s += u - i;
    rep(l, 20)
      g[l] = h[l];
    rep(j, d[i].size())
      g[d[i][j]] = false;
    rep(j, 20)
      h[j] = g[j];
  }
  out(s);
  memi;
}