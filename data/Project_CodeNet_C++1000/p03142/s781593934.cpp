#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << endl; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> in(n, 0);
  REP(i, n - 1 + m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    in[b]++;
  }

  int root = 0;
  REP(i, n) {
    if (in[i] == 0) {
      root = i;
      break;
    }
  }

  vector<int> ans(n);
  queue<int> q;
  ans[root] = -1;
  q.push(root);
  while (!q.empty()) {
    int rt = q.front();
    q.pop();
    for (const auto v : g[rt]) {
      in[v]--;
      if (in[v] == 0) {
        ans[v] = rt;
        q.push(v);
      }
    }
  }
  REP(i, n) { cout << ans[i] + 1 << endl; }
  return 0;
}
