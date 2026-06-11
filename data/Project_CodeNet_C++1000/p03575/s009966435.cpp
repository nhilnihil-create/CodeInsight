#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

V<V<int>> g;
V<bool> checked;
int n1;
int n2;

void dfs(int v) {
  checked[v] = true;
  for (auto n : g[v]) {
    if (checked[n]) continue;
    if ((v == n1 && n == n2) || (v == n2 && n == n1)) continue;
    dfs(n);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  V<int> a(m), b(m);
  rep(i, m) {
    int ai, bi;
    cin >> ai >> bi;
    a[i] = --ai;
    b[i] = --bi;
  }
  g.resize(n);
  checked.resize(n);
  rep(i, m) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  int ans = 0;
  rep(i, m) {
    fill(checked.begin(), checked.end(), false);
    n1 = a[i];
    n2 = b[i];
    dfs(0);
    bool ok = true;
    V<bool> t = checked;
    rep(i, n) if (!checked[i]) ok = false;
    if (!ok) ans++;
  }
  cout << ans << endl;
}
