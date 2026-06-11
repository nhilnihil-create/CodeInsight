#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
#define endl '\n'
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll n, k;
  cin >> n >> k;
  vector<vll> p(n, vll(2)), q(n, vll(2));
  for (ll i = 0; i < n; i++) {
    cin >> p[i][0] >> p[i][1];
    q[i][0] = p[i][1];
    q[i][1] = p[i][0];
  }
  sort(all(p));
  sort(all(q));
  ll ans = inf;
  for (ll i = 0; i + k - 1 < n; i++) {
    for (ll j = i + k - 1; j < n; j++) {
      vector<vll> v;
      for (ll l = i; l <= j; l++) {
        v.push_back(p[l]);
        swap(v.back()[0], v.back()[1]);
      }
      sort(all(v));
      for (ll m = 0; m + k - 1 < v.size(); m++) {
        ll xmax = -1e9, xmin = 1e9, ymax = -1e9, ymin = 1e9;
        for (ll r = 0; r < k; r++) {
          xmax = max(xmax, v[m + r][0]);
          xmin = min(xmin, v[m + r][0]);
          ymax = max(ymax, v[m + r][1]);
          ymin = min(ymin, v[m + r][1]);
        }
        ans = min(ans, (xmax - xmin) * (ymax - ymin));
      }
    }
  }
  for (ll i = 0; i + k - 1 < n; i++) {
    for (ll j = i + k - 1; j < n; j++) {
      vector<vll> v;
      for (ll l = i; l <= j; l++) {
        v.push_back(q[l]);
        swap(v.back()[0], v.back()[1]);
      }
      sort(all(v));
      for (ll m = 0; m + k - 1 < v.size(); m++) {
        ll xmax = -1e9, xmin = 1e9, ymax = -1e9, ymin = 1e9;
        for (ll r = 0; r < k; r++) {
          xmax = max(xmax, v[m + r][0]);
          xmin = min(xmin, v[m + r][0]);
          ymax = max(ymax, v[m + r][1]);
          ymin = min(ymin, v[m + r][1]);
        }
        ans = min(ans, (xmax - xmin) * (ymax - ymin));
      }
    }
  }
  cout << ans << endl;
}