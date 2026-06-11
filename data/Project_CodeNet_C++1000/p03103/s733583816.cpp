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
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> a(n);
  rep(i,n) cin >> a[i].first >> a[i].second;
  sort(ALL(a));
  ll c = 0;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (c >= m) break;
    if (c + a[i].second <= m) {
      ans += a[i].first * a[i].second;
    } else {
      ans += a[i].first * (m - c);
    }
    c += a[i].second;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}