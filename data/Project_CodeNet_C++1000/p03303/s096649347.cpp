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

void solve()
{
  // ll x, y, z; cin >> x >> y >> z;
  string s; cin >> s;
  ll n; cin >> n;
  // vector<ll> a(n); REP(i, n) cin >> a[i];
  // ll ans = 0;
  // bool ok = false;
  for(ll i = 0; i < s.size(); i+=n) {
    cout << s[i];
  }
  cout << endl;
  // cout << ans << endl;
  // cout << (ok?"Yes":"No") << endl;}
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
