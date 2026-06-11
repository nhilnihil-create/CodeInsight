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

  ll n, m;
  cin >> n >> m;
  V a(n);
  rep(i,n) cin >> a[i];
  vector<pair<ll,ll>> b(m);
  rep(i,m) {
    cin >> b[i].second >> b[i].first;
  }
  sort(All(b));
  reverse(All(b));
  ll cnt = 0;
  rep(i,m) {
    rep(j,b[i].second) {
      a.push_back(b[i].first);
      ++cnt;
    }
    if (cnt >= n) break;
  }
  sort(All(a));
  reverse(All(a));
  ll ans = 0;
  rep(i,n) {
    ans += a[i];
  }
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}