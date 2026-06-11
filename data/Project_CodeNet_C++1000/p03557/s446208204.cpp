#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));
  ll ans = 0;
  for (ll m: b) {
    ll l = lower_bound(ALL(a), m) - a.begin();
    ll r = n - (upper_bound(ALL(c), m) - c.begin());
    if (!(0 <= l && l <= n) || !(0 <= r && r <= n)) continue;
    ans += l * r; 
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}