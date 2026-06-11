#include <bits/stdc++.h>
using namespace std;

vector<int> g[10000];
int c[10000];
int d[10000];
int idx_c = 0;

void dfs(int cur, int p) {
  d[cur] = c[idx_c];
  ++idx_c;
  for (int to: g[cur]) {
    if (to == p) {
      continue;
    }
    dfs(to, cur);
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
  for (int i=0; i<n; i++) cin>>c[i];
  sort(c, c + n);
  reverse(c, c + n);

  dfs(0, -1);
  long long m = 0;
  for (int i=1; i<n; i++) m += c[i];
  cout<<m<<endl;
  for (int i=0; i<n; i++) {
    cout<<d[i];
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
}