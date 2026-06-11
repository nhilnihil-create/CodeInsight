#include <bits/stdc++.h>
using namespace std;

int N, M;
int par[100010];
int depth[100010];


void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i+1] = i+1;
    depth[i+1] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  
  if (depth[x] < depth[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (depth[x] == depth[y]) depth[x]++;
  }
  
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int main() {
  
  cin >> N >> M;
  int P[N+1];

  
  init(N);
  
  for (int i = 0; i < N; i++)  cin >> P[i+1];
  
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    unite(x, y);
  }
  
  
  
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (same(i, P[i])) ans++;
  }

  cout << ans << endl;

}