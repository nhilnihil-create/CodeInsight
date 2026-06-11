#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

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
  V<V<int>> to(n);
  rep(i, m) {
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }

  int ans = 0;
  rep(i, m) {
    V<int> c(n);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      c[f] = 1;
      for (auto t : to[f]) {
        if (c[t] != 0) continue;  // 訪問済み
        if ((f == a[i] && t == b[i]) || (t == a[i] && f == b[i])) continue;
        q.push(t);
      }
    }
    bool ok = true;
    rep(i, n) if (c[i] == 0) ok = false;
    if (!ok) ans++;
  }
  cout << ans << endl;
}
