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

string key = "keyence";

void solve()
{
  string s; cin >> s;
  // vector<ll> a(n); REP(i, n) cin >> a[i];
  // ll ans = 0;
  bool ok = false;
  REP(i, 7) {
    //    if(s[i] == key[i])
  }
  if(key == s.substr(0, 7)) ok = true;
  else if(key == s.substr(s.size()-7, 7)) ok = true;
  else {
    int l = 0, r = 0;
    for(l = 0; key[l] == s[l]; l++);
    for(r = 0; key[7-r-1] == s[s.size()-r-1]; r++);
    if(r + l >= 7) ok = true;
  }
  // cout << ans << endl;
  cout << (ok?"YES":"NO") << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
