#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> g[100000];
set<int> rev_g[100000];

void solve(int cur) {
  set<int> remove;
  for (int to: g[cur]) {
    if (rev_g[to].size() > 1) {
      remove.insert(to);
    }
  }
  for (int i: remove) {
    g[cur].erase(i);
    rev_g[i].erase(cur);
  }
  for (int to: g[cur]) {
    solve(to);
  }
}
int main() {
  cin>>n>>m;
  for (int i=0; i<n-1+m; i++) {
    int a, b;
    cin>>a>>b;
    --a;
    --b;
    g[a].insert(b);
    rev_g[b].insert(a);
  }
  int root;
  for (int i=0; i<n; i++) {
    if (rev_g[i].size() == 0) {
      root = i;
      break;
    }
  }
  solve(root);
  for (int i=0; i<n; i++) {
    if (i == root) {
      cout<<0<<endl;
    } else {
      cout<<*rev_g[i].begin() + 1<<endl;
    }
  }
}