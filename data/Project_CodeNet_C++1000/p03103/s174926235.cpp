#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pll> v(n);
  rep(i,n) cin >> v[i].first >> v[i].second;
  sort(ALL(v));
  ll c = 0;
  ll ans = 0;
  rep(i,n) {
    if (c == m) break;
    ll l = m - c;
    if (l >= v[i].second) {
      c += v[i].second;
      ans += v[i].first * v[i].second;
    } else {
      c += l;
      ans += v[i].first * l;
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}