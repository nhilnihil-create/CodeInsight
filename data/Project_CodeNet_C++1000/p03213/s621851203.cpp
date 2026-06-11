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
  ll n, a, b, x;
  in(n);
  vector<ll> c(100, 1), d;
  x = 0;
  rep(i, n){
    a = i + 1;
    b = 2;
    while(a > 1){
      if(a % b == 0){
        a /= b;
        c[b]++;
      }
      else
        b++;
    }
  }
  rep(i, 100){
    if(c[i] != 1)
      d.pb(c[i]);
  }
  n = d.size();
  rep(i, n){
    if(d[i] >= 75)
      x++;
    rep2(j, i + 1, n){
      if(d[i] >= 15 && d[j] >= 5){
        x++;
      }
      if(d[i] >= 5 && d[j] >= 15){
        x++;
      }
      if(d[i] >= 25 && d[j] >= 3){
        x++;
      }
      if(d[i] >= 3 && d[j] >= 25){
        x++;
      }
      rep2(k, j + 1, n){
        if(d[i] >= 3 && d[j] >= 5 && d[k] >= 5){
          x++;
        }
        if(d[i] >= 5 && d[j] >= 3 && d[k] >= 5){
          x++;
        }
        if(d[i] >= 5 && d[j] >= 5 && d[k] >= 3){
          x++;
        }
      }
    }
  }
  out(x);
  memi;
}