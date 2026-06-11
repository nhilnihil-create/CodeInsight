#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll h, w;
vector <vector <bool>> v(50, vector <bool> (50, 0));
vector <vector <ll>> d(50, vector <ll> (50, INF));
vector <ll> nx = {1, -1, 0, 0};
vector <ll> ny = {0, 0, -1, 1};

void dfs(ll x, ll y) {
  rep(i, 4) {
    ll px = x+nx.at(i), py = y+ny.at(i);
    if (0<=px&&px<h && 0<=py&&py<w) {
      if (d.at(x).at(y)+1<d.at(px).at(py) && v.at(px).at(py)) {
        d.at(px).at(py) = d.at(x).at(y) + 1;
        dfs(px, py);
      }
    }
  }
  return;
}

int main() {
  cin >> h >> w;
  ll white = 0;
  rep(i, h) {
    rep(j, w) {
      char c;
      cin >> c;
      if (c == '.') {
        v.at(i).at(j) = 1;
        white++;
      }
    }
  }
  d.at(0).at(0) = 0;
  dfs(0, 0);
  if (d.at(h-1).at(w-1) == INF) cout << -1 << endl;
  else cout << white-d.at(h-1).at(w-1)-1 << endl;
}