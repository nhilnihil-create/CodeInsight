#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll INF = 4e18;
const ll MOD = 1e9+7;

ll n, m;
vector<int> G[100010];
map<int,bool> mp;
int cnt;

bool f (int k, bool g) {
  if (mp.count(k)) return !(mp[k]^g);

  mp[k] = g;
  if (g) cnt++;
  bool ff = 1;
  for (int i = 0; i < G[k].size(); i++) {
    ff &= f(G[k][i], !g);
  }
  return ff;
}

bool ok() {
  return !f(1, 0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (ll i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  if (ok()) {
    cout << (n - 1) * n / 2 - m << endl;
  } else {
    cout << cnt * (n-cnt) - m << endl;
  }
  return 0;
}
