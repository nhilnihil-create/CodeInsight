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
  ll x, y, z, k, s;
  in3(x, y, z);
  in(k);
  vector<ll> a(x), b(y), c(z), d, e;
  rep(i, x)
    in(a[i]);
  rep(i, y)
    in(b[i]);
  rep(i, z)
    in(c[i]);
  rep(i, x){
    rep(j, y)
      d.pb(a[i] + b[j]);
  }
  sort(all(d));
  reverse(all(d));
  s = 0;
  if(d.size() > k)
    s = d.size() - k;
  rep(i, s)
    d.pop_back();
  rep(i, d.size()){
    rep(j, z)
      e.pb(d[i] + c[j]);
  }
  sort(all(e));
  reverse(all(e));
  rep(i, k){
    out(e[i]);
    memi;
  }
}