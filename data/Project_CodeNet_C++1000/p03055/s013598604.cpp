#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> g[200000];

void dfs(int cur, int p, vector<int> &cost) {
  for (int to: g[cur]) {
    if (to == p) {
      continue;
    }
    cost[to] = cost[cur] + 1;
    dfs(to, cur, cost);
  }
}
int main() {
  int n;
  cin>>n;
  for (int i=0; i<n-1; i++) {
    int a, b;
    cin>>a>>b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> cost(n);
  dfs(0, -1, cost);
  int i_max = 0;
  for (int i=0; i<n; i++) {
    if (cost[i] > cost[i_max]) {
      i_max = i;
    }
  }
  vector<int> cost2(n);
  dfs(i_max, -1, cost2);
  int max_cost = 0;
  for (int i=0; i<n; i++) {
    max_cost = max(cost2[i], max_cost);
  }
  if (max_cost % 3 == 1) {
    cout<<"Second"<<endl;
  } else {
    cout<<"First"<<endl;
  }
}