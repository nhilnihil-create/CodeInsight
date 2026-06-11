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

//UnionFind
//全て添字で扱うこと
struct uf {
  vll parent;

  void init_uf(ll n) {
    for (ll i = 0; i < n; i++) parent.push_back(i);
    return;
  }

  ll root(ll n) {
    if (parent[n] == n) return n;
    return parent[n] = root(parent[n]);
  }

  void unite(ll a, ll b) {
    ll ra = root(a), rb = root(b);
    parent[rb] = ra;
    return;
  }
};

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

  uf uf1;
  uf1.init_uf(n);

  for (ll i = 0; i < m; i++) {
    uf1.unite(xy[i][0] - 1, xy[i][1] - 1);
  }

  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (uf1.root(i) == uf1.root(p[i] - 1)) cnt++;
  }
  cout << cnt << endl;
}