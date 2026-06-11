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
  ll d,n, k; cin >> n >> k;
  // ll x, y, z; cin >> x >> y >> z;
  // string s; cin >> s;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  ll ans = -1;

  sort(a.begin(), a.end());

  REP(i, n - k + 1) {
    d = a[i + k - 1] - a[i];
    if(ans < 0 || ans > d) ans = d;
  }
  
  cout << ans << endl;
  
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
