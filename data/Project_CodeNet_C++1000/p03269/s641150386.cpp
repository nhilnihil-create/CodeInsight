#include <bits/stdc++.h>
using namespace std;

struct edge1 {
  int to, cost;
};
struct edge2 {
  int from, cost;
};
int main() {
  int l;
  cin>>l;
  vector<edge1> g[20];
  vector<edge2> tmp;
  int cur = 0;
  --l;
  int n_edge = 0;
  while (l > 0) {
    int cost;
    if (l % 2 == 0) {
      cost = l / 2 + 1;
      g[cur].push_back({cur+1, cost});
      g[cur].push_back({cur+1, 0});
      tmp.push_back({cur, cost - 1});
      n_edge += 3;
    } else {
      cost = (l + 1) / 2;
      g[cur].push_back({cur+1, cost});
      g[cur].push_back({cur+1, 0});
      n_edge += 2;
    }
    ++cur;
    l -= cost;
  }
  for (auto e: tmp) {
    g[e.from].push_back({cur, e.cost});
  }
  cout<<cur+1<<" "<<n_edge<<endl;
  for (int i=0; i<cur; i++) {
    for (auto e: g[i]) {
      cout<<i+1<<" "<<e.to+1<<" "<<e.cost<<endl;
    }
  }
}