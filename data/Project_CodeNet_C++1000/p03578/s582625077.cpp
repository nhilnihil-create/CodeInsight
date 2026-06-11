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
  vector<ll> d(n);
  rep(i,n) cin >> d[i];
  ll m;
  cin >> m;
  vector<ll> t(m);
  rep(i,m) cin >> t[i];
  sort(All(d));
  sort(All(t));

  ll now = 0;
  for (ll i = 0; i < m; ++i) {
    for (ll j = now; j < n+1; ++j) {
      if (j == n) {
        cout << "NO\n";
        return 0;
      }
      if (t[i] == d[now]) {
        ++now;
        break;
      }  
      else ++now;
    }
  }
  cout << "YES\n";

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}