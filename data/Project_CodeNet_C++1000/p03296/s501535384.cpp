#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n-1) {
    if(a[i] == a[i+1]) {
      a[i+1] = -1;
      ans++;
    }
  }
  cout << ans << "\n";
}