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
  ll n, a, b;
  in(n);
  vector<ll> c(n);
  rep(i, n)
    in(c[n - i - 1]);
  if(c[0] != 2){
    out(-1);
    memi;
    return 0;
  }
  a = 2;
  b = 3;
  rep2(i, 1, n){
    if((a - 1) / c[i] == b / c[i]){
      out(-1);
      memi;
      return 0;
    }
    a = ((a + c[i] - 1) / c[i]) * c[i];
    b = (b / c[i] + 1) * c[i] - 1;
  }
  out(a);
  hina;
  out(b);
  memi;
}