#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int id = 0;
vector<int> c;
vector<vector<int>> g;
vector<int> seen;
vector<int> value;
void dfs(int node) {
  if(seen[node]) return;
  seen[node] = 1;
  value[node] = c[id];
  id++;
  for(auto& next : g[node]) {
    if(!seen[next]) dfs(next);
  }
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  c.resize(n);
  seen.resize(n);
  value.resize(n);
  for(int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  for(int i=0;i<n;i++) cin >> c[i];
  sort(c.rbegin(), c.rend());
  dfs(0);
  long long m = 0;
  for(int i=0;i<n;i++) {
    for(auto& el : g[i]) {
      m += min(value[i], value[el]);
    }
  }
  cout << m / 2 << endl;
  for(int i=0;i<n;i++) cout << value[i] << endl;
  return 0;
}
