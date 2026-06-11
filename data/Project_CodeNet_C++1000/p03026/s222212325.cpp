#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  rep(i,n-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  vector<int> c(n);
  int sum = 0;
  rep(i,n) cin >> c[i], sum += c[i];
  sort(c.begin(), c.end(), greater<int>());
  sum -= c.front();
  queue<P> que;
  vector<P> res;
  que.push(make_pair(0,-1));
  int idx = 0;
  while (!que.empty()) {
    P ver = que.front(); que.pop();
    int u = ver.first, p = ver.second; 
    res.emplace_back(make_pair(u,c[idx]));
    idx++;
    for (auto v : g[u]) {
      if (v == p) continue;
      que.push(make_pair(v,u));
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