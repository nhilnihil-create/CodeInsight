#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int l[m], r[m], d[m];
  for (int i = 0; i < m; i++) cin >> l[i] >> r[i] >> d[i];
  vector<P> info[n];
  for (int i = 0; i < m; i++) {
    info[l[i] - 1].push_back(P(r[i] - 1, d[i]));
    info[r[i] - 1].push_back(P(l[i] - 1, -d[i]));
  }
  int x[n];
  memset(x, -1, sizeof(x));
  string res = "Yes";
  for (int i = 0; i < n; i++) {
    stack<int> q;
    if (x[i] != -1) continue;
    else {
      x[i] = (int) 1e9;
      q.push(i);
    }
    while (q.size()) {
      int v = q.top();
      q.pop();
      for (auto p : info[v]){
        int u = p.first;
        if (x[u] == -1) {
          x[u] = x[v] + p.second;
          q.push(u);
        } else {
          if (x[u] != x[v] + p.second) {
            cout << "No" << "\n";
            return 0;
          }
        }
      }
    }
  }
  cout << res << "\n";
  return 0;
}