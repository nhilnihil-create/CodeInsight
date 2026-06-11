#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int n, k;
bool has_enough(ll xmin, ll xmax, ll ymin, ll ymax, vector<P> &xy){
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    ll x = xy[i].first;
    ll y = xy[i].second;
    if (x >= xmin && x <= xmax && y >= ymin && y <= ymax)
      cnt++;
  }
  return cnt >= k;
}
int main() {
  cin >> n >> k;
  vector<P> xy(n);
  vector<ll> x(n);
  vector<ll> y(n);
  
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    cin >> y[i];
    xy[i] = P(x[i], y[i]);
  }
  
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  ll ans = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
  for (int x1 = 0; x1 < n; ++x1) {
    for (int x2 = x1 + 1; x2 < n; x2++) {
      for (int y1 = 0; y1 < n; ++y1) {
        for (int y2 = y1 + 1; y2 < n; ++y2) {
          ll xmin = min(x[x1], x[x2]);
          ll xmax = max(x[x1], x[x2]);
          ll ymin = min(y[y1], y[y2]);
          ll ymax = max(y[y1], y[y2]);
          if (has_enough(xmin, xmax, ymin, ymax, xy))
            ans = min(ans, abs(xmax - xmin) * abs(ymax - ymin));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}