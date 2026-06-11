#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using P = pair<int,int>;

const int MAX = 2e5;
struct edge{int to, cost;};
struct Diameter{int from, to, d;};
vector<edge> g[MAX];

P farthest(int u,int p) {
  P r(0,u);
  for(auto e : g[u]) {
    if(e.to == p) continue;
    P c = farthest(e.to,u);
    c.first += e.cost;
    r = max(r,c);
  }
  return r;
}

Diameter tree_diameter() {
  P p = farthest(0,-1);
  P q = farthest(p.second,-1);
  return Diameter{p.second,q.second,q.first}; 
}

int main(){
  int n;
  cin >> n;
  rep(i,n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(edge{b,1});
    g[b].push_back(edge{a,1});
  }
  Diameter d = tree_diameter();
  cout << (d.d % 3 == 1 ? "Second" : "First") << endl;
  return 0;
}