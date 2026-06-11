#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> vc(n);
  for (int i = 0; i < n; ++i) {
    cin >> vc[i];
  }

  sort(vc.begin(), vc.end(), greater<int>());

  int m = accumulate(vc.begin() + 1, vc.end(), 0);
  cout << m << '\n';

  vector<int> ans(n);
  int cur = 0;
  queue<int> q;
  vector<bool> seen(n, false);
  q.push(0);
  while (!q.empty()) {
    int idx = q.front();
    q.pop();
    if (seen[idx]) {
      continue;
    }

    seen[idx] = true;
    ans[idx] = vc[cur++];
    for (auto c : g[idx]) {
      q.push(c);
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}