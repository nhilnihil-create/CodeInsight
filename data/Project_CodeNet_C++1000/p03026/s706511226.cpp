#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;
constexpr int INF = 2e9;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  vector<vector<int>> g(n);
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  rep(i,n) cin >> c[i];
  sort(c.begin(), c.end(), greater<int>());
  int sum = accumulate(c.begin() + 1, c.end(), 0);

  queue<P> que;
  vector<P> res;
  que.push(make_pair(0, -1));
  int id = 0;
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    int u = p.first;
    int par = p.second;
    res.emplace_back(make_pair(u, c[id]));
    id++;
    for (auto v : g[u]) {
      if (v == par) continue;
      que.push(make_pair(v, u));
    }
  }
  sort(res.begin(), res.end());
 
  cout << sum << endl;
  for (auto e : res) {
    cout << e.second << " ";
  }
  cout << endl;
  return 0;
} 