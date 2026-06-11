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
  ll n, c;
  cin >> n >> c;
  vector<vll> grid(n, vll(n)), d(c, vll(c));
  for (ll i = 0; i < c; i++) {
    for (ll j = 0; j < c; j++) {
      cin >> d[i][j];
    }
  }
  vector<vll> mod(3, vll(0));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> grid[i][j];
      mod[(i + j) % 3].push_back(grid[i][j]);
    }
  }
  ll ans = inf;
  for (ll i = 0; i < c; i++) {
    ll d1 = 0;
    for (ll x = 0; x < mod[0].size(); x++) {
      d1 += d[mod[0][x] - 1][i];
    }
    for (ll j = 0; j < c; j++) {
      if (i == j) continue;
      ll d2 = d1;
      for (ll x = 0; x < mod[1].size(); x++) {
        d2 += d[mod[1][x] - 1][j];
      }
      for (ll k = 0; k < c; k++) {
        if (i == k || j == k) continue;
        ll d3 = d2;
        for (ll x = 0; x < mod[2].size(); x++) {
          d3 += d[mod[2][x] - 1][k];
        }
        ans = min(ans, d3);
      }
    }
  }
  cout << ans << endl;
}