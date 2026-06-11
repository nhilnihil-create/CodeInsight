#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<char> group(n);
  for (int i = 0; i < n; i++) {
    cin >> group[i];
  }
  vector<vector<int>> grh(n);
  vector<int> cntA(n, 0);
  vector<int> cntB(n, 0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    for (int k = 0; k < 2; k++) {
      grh[a].push_back(b);
      if (group[a] == 'A') {
        cntA[b]++;
      } else {
        cntB[b]++;
      }
      swap(a, b);
    }
  }
  vector<bool> hbdel(n, false);
  stack<int> del;
  for (int i = 0; i < n; i++) {
    if (!(cntA[i] && cntB[i])) {
      del.push(i);
     hbdel[i] = true;
    }
  }
  while (!del.empty()) {
    int crr = del.top();
    del.pop();
    for (int nxt : grh[crr]) {
      if (hbdel[nxt]) {
        continue;
      }
      if (group[crr] == 'A') {
        cntA[nxt]--;
      } else {
        cntB[nxt]--;
      }
      if (!(cntA[nxt] && cntB[nxt])) {
        del.push(nxt);
        hbdel[nxt] = true;
      }
    }
  }
  bool ret = false;
  for (int i = 0; i < n; i++) {
    if(!hbdel[i]) {
      ret = true;
    }
  }
  if (ret) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}