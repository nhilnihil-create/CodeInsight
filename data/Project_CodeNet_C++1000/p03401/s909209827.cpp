#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
const ll mod = 1e9+7;
const ll INF = 1e18;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;
using P = pair<ll,ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  V a(n+2);
  ll s = 0;
  rep(i,n+1) {
    cin >> a[i+1];
    s += abs(a[i+1]-a[i]);
  }
  Rep(i,1,n+1) {
    if ((a[i] >= a[i-1] && a[i] <= a[i+1]) || (a[i] <= a[i-1] && a[i] >= a[i+1])) {
      cout << s << '\n';
    }
    else {
      ll t = min(abs(a[i]-a[i-1]), abs(a[i]-a[i+1]));
      cout << s-2*t << '\n';
    }
  }

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}