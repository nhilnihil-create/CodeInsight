#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  string s;
  ll n;
  cin >> n >> s;
  
  vector<ll> a(n, 0);
  vector<ll> e(n+1, 0);
  rep(i, 0, n) {
    if(s[i]=='E') a[i]++;
    e[i+1] = e[i]+a[i];
  }
  
  ll ans = 300001;
  rep(i, 1, n+1) {
    ll cnt = 0;
    cnt += i-1-e[i-1];
    cnt += e[n]-e[i];
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}