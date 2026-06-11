#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

ll root(ll x, vll &parent) {
  if (parent[x] == x) return x;
  else return parent[x] = root(parent[x], parent);
}

int main() {
  ll n, m;
  cin >> n >> m;

  vll p(n);
  for (ll i = 0; i < n; i++) cin >> p[i];

  vector<vll> xy(m, vll(2));
  for (ll i = 0; i < m; i++) {
    cin >> xy[i][0] >> xy[i][1];
    if (xy[i][0] > xy[i][1]) swap(xy[i][0], xy[i][1]);
  }

  vll parent(n);
  for (ll i = 0; i < n; i++) parent[i] = i;
  for (ll i = 0; i < m; i++) {
    parent[root(xy[i][1] - 1, parent)] = root(xy[i][0] - 1, parent);
  }

  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (root(i, parent) == root(p[i] - 1, parent)) cnt++;
  }
  cout << cnt << endl;
}