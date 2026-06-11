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
using Graph = vector<vector<ll>>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, h;
  cin >> n >> h;
  vector<ll> a(n);
  vector<ll> b(n);
  ll ans = 0;
  rep(i,n) {
    cin >> a[i] >> b[i];
  }
  sort(All(a));
  sort(All(b));
  ll A = a[n-1];
  for (ll i = n-1; i >= 0; --i) {
    if (A < b[i]) {
      h -= b[i];
      ++ans;
    }
    else {
      break;
    }
    if (h <= 0) {
      cout << ans << '\n';
      return 0;
    }
  }
  ans += (h+A-1)/A;
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}