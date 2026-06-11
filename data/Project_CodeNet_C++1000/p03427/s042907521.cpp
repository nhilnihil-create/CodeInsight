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
  ll n, a, b, c, d;
  in(n);
  a = n;
  b = 0;
  if(n < 10){
    out(n);
    memi;
    return 0;
  }
  while(a / 10 != 0){
    a /= 10;
    b++;
  }
  a = 9;
  rep(i, b - 1){
    a = a * 10 + 9;
  }
  c = a + 1;
  b = b * 9;
  d = b;
  rep(i, 10){
    if((i + 1) * c + a <= n){
      d = b + i + 1;
    }
  }
  out(d);
  memi;
}
