#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  V a(n);
  rep(i,n) cin >> a[i];
  V s(n+1);
  rep(i,n) {
    s[i+1] = gcd(s[i],a[i]);
  }
  V t(n+1);
  for (ll i = n-1; i >= 0; --i) {
    if (i == n-1) t[i] = a[i];
    else {
      t[i] = gcd(t[i+1], a[i]);
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    ll tmp = gcd(s[i-1],t[i]);
    ans = max(ans,tmp);
  }
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}