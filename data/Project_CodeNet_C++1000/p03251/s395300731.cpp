#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void)
{
  ll n, m, X, Y; cin >> n >> m >> X >> Y;
  ll mx = X;
  ll my = Y;
  vector<ll> x(n);
  REP(i, n) {
    cin >> x[i];
    if(mx < x[i]) mx = x[i];
  }
  vector<ll> y(m);
  REP(i, m) {
    cin >> y[i];
    if(my > y[i]) my = y[i];
  }
  
  // ll ans = 0;
  bool ok = false;
  if(mx<my) ok = true;
  
  // cout << ans << endl;
  cout << (ok?"No War":"War") << endl;
}
