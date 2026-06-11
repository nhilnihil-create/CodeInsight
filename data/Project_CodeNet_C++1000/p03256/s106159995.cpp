#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<int>> grh, cnt;
vector<int> ckd;
void dfs (int crr) {
  if (ckd[crr]) return;
  if (cnt[crr][0] && cnt[crr][1]) return;
  ckd[crr] = true;
  for (int nxt : grh[crr]) {
    if (ckd[nxt]) continue;
    if (s[crr] == s[nxt]) {
      cnt[crr][0]--;
      cnt[nxt][0]--;
    } else {
      cnt[crr][1]--;
      cnt[nxt][1]--;
    }
    dfs(nxt);
  }
}
int main() {
  int n, m;
  cin >> n >> m >> s;
  grh.resize(n);
  cnt.resize(n, vector<int>(2));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    grh[a].push_back(b);
    grh[b].push_back(a);
    if (s[a] == s[b]) {
      cnt[a][0]++;
      cnt[b][0]++;
    } else {
      cnt[a][1]++;
      cnt[b][1]++;
    }
  }
  ckd.resize(n, false);
  for (int i = 0; i < n; i++) {
    dfs(i);
  }
  int flg = false;
  for (int i = 0; i < n; i++) {
    if (!ckd[i]) flg = true;
  }
  if (flg) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}