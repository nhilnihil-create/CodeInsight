#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> g(n);
  vector<int> erased(n);
  vector<int> degA(n), degB(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      if (s[j] == 'A') degA[i]++;
      if (s[j] == 'B') degB[i]++;
    }
    if (degA[i] == 0 || degB[i] == 0) que.push(i), erased[i] = 1;
  }
  while (que.size()) {
    int cur = que.front();
    que.pop();
    for (int nxt : g[cur]) if (nxt != cur && !erased[nxt]) {
      if (s[cur] == 'A') degA[nxt]--;
      if (s[cur] == 'B') degB[nxt]--;
      if (degA[nxt] == 0 || degB[nxt] == 0) que.push(nxt), erased[nxt] = 1;
    }
  }
  for (int i = 0; i < n; i++) if (!erased[i]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}