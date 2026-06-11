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
  ll a, b, c, n, h;
  in2(n, c);
  vector<vector<ll>> d(c, vector<ll> (c));
  vector<vector<ll>> e(n, vector<ll> (n));
  rep(i, c){
    rep(j, c)
      in(d[i][j]);
  }
  rep(i, n){
    rep(j, n){
      in(e[i][j]);
      e[i][j]--;
    }
  }
  vector<ll> s(c, 0), t(c, 0), u(c, 0);
  rep(i, n){
    rep(j, n){
      if((i + j) % 3 == 0)
        s[e[i][j]]++;
      if((i + j) % 3 == 1)
        t[e[i][j]]++;
      if((i + j) % 3 == 2)
        u[e[i][j]]++;
    }
  }
  a = 9999999999999;
  rep(i, c){
    rep(j, c){
      rep(k, c){
        if(i != j && j != k && k != i){
          h = 0;
          rep(l, c){
            h += s[l] * d[l][i];
            h += t[l] * d[l][j];
            h += u[l] * d[l][k];
          }
          a = min(h, a);
        }
      }
    }
  }
  out(a);
  memi;
}