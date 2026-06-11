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

void dfs(int cur, int par, const vector<vi> &g, vi &d) {
  int cur_d = d[cur];
  for (const auto el : g[cur]) {
    if (par == el)
      continue;
    d[el] = cur_d + 1;
    dfs(el, cur, g, d);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vi> g(n);
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vi d(n);
  d[0] = 1;
  dfs(0, -1, g, d);
  int ma = 0, mai;
  REP(i, n) {
    if (d[i] > ma) {
      chmax(ma, d[i]);
      mai = i;
    }
  }

  d[mai] = 1;
  dfs(mai, -1, g, d);
  int diam = 0;
  REP(i, n) { chmax(diam, d[i]); }

  if (diam % 3 == 2) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }

  return 0;
}
