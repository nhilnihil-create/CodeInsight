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
  vector<ll> a(n+1);
  rep(i,n) cin >> a[i];
  a[n] = 1000000001;
  sort(All(a));
  ll ans = 0;
  ll cnt = 1;
  rep(i,n) {
    if (a[i] == a[i+1]) {
      ++cnt;
    }
    else {
      if (cnt >= a[i]) {
        ans += cnt - a[i];
      }
      else {
        ans += cnt;
      }
      cnt = 1;
    }
  }
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}