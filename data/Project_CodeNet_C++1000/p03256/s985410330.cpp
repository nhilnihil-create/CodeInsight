#include <bits/stdc++.h>
using namespace std;
vector<int> ckd;
vector<vector<int>> grh;
void dfs (int crr, int prt) {
  if (ckd[crr] == 2) return;
  ckd[crr] = 1;
  for (int nxt : grh[crr]) {
    if (ckd[nxt] == 1) {
      cout << "Yes" << '\n';
      exit(0);
    }
    dfs(nxt, crr);
  }
  ckd[crr] = 2;
}
int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  grh.resize(2 * n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (s[a] == s[b]) {
      grh[a].push_back(b + n);
      grh[b].push_back(a + n);
    } else {
      grh[a + n].push_back(b);
      grh[b + n].push_back(a);
    }
  }
  ckd.resize(2 * n, 0);
  for (int i = 0; i < 2 * n; i++) {
    dfs(i, i);
  }
  cout << "No" << '\n';
  return 0;
}