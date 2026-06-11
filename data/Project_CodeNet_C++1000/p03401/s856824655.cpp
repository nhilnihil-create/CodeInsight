#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  int n;
  cin >> n;
  vll a(n+2);
  a[0] = 0;
  a[n+1] = 0;
  rep(i,n) cin >> a[i+1];
  vll b(n+1);
  rep(i,n+1) b[i] = abs(a[i+1]-a[i]);
  vll c(n);
  rep(i,n) c[i] = abs(a[i+2]-a[i]);
  ll cnt = 0;
  rep(i,n+1) cnt += b[i];
  rep(i,n) {
    ll ans = cnt;
    ans -= (b[i]+b[i+1]);
    ans += c[i];
    cout << ans << endl;
  }
  return 0;
}