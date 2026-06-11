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
  ll n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  ll ans = 0;
  sort(a.begin(), a.end());
  ll i = 0;
  while(i < n) {
    ll a1 = a[i];
    ll cnt = 0;
    while(i < n && a[i] == a1) {
      cnt ++; i++;
    }
    //    cout << a1 << " " << cnt << endl;
    if(cnt > a1) {
      ans += cnt - a1;
    } else if(cnt < a1) {
      ans += cnt;
    }
  }
  
  cout << ans << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
