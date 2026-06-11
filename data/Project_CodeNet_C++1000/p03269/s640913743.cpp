#include <bits/stdc++.h>
using namespace std;

int n, m, L;
vector<pair<int, int>> adj[25];

void addEdge(int u, int v, int w) {
  ++m;
  adj[u].emplace_back(v, w);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> L;
  int r = 0;
  while (1 << (r + 1) <= L) ++r;
  n = r + 1;
  for (int i = 1; i < n; ++i) {
    addEdge(i, i + 1, 0);
    addEdge(i, i + 1, 1 << (i - 1));
  }
  int done = (1 << r) - 1;
  while (done < L - 1) {
    int t = 1;
    while (done + (1 << t) < L) ++t;
    addEdge(t, n, done + 1);
    done += 1 << (t - 1);
  }
  cout << n << " " << m << "\n";
  for (int i = 1; i <= n; ++i)
    for (auto &p: adj[i])
      cout << i << " " << p.first << " " << p.second << "\n";
  return 0;
}