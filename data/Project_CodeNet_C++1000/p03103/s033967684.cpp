#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<ll,ll>> v(n);
  rep(i, 0, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());

  ll ans = 0;
  int c = 0;
  rep(i, 0, n) {
    if (c + v[i].second > m){
      ans += (m - c) * v[i].first;
      break;
    }
    else
      ans += v[i].second * v[i].first;
    c += v[i].second;
  }

  cout << ans << endl;
}
