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
  a = 0;
  vector<ll> c(n + 2, 0), d(n + 1), e(n);
  rep(i, n){
    in(c[i + 1]);
  }
  rep(i, n + 1)
    d[i] = abs(c[i + 1] - c[i]);
  rep(i, n){
    e[i] = abs(c[i + 2] - c[i]);
  }
  rep(i, n + 1){
    a = a + d[i];
  }
  rep(i, n){
    b = a - d[i] - d[i + 1] + e[i];
    out(b);
    memi;
  }
}