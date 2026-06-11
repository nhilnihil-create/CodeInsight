#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  ll mc = 0;
  ll zero = 0;
  vector<ll> a(n);
  rep(i,n) {
    ll t;
    cin >> t;
    if (t < 0) ++mc;
    if (t == 0) ++zero;
    a[i] = abs(t);
  }
  sort(All(a));
  ll ans = 0;
  if (zero > 0 || mc%2 == 0) {
    rep(i,n) {
      ans += a[i];
    }
  }
  else {
    rep(i,n-1) {
      ans += a[i+1];
    }
    ans -= a[0];
  }
  cout << ans << '\n';


  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}