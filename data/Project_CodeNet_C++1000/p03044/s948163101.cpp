#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  vector<vector<int>> cost(n);

  rep(i, n - 1) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    tree.at(a).push_back(b);
    cost.at(a).push_back(w);
    tree.at(b).push_back(a);
    cost.at(b).push_back(w);
  }

  vector<int> ans(n, -1);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    rep(i, tree.at(v).size()) {
      int u = tree.at(v).at(i);
      int w = cost.at(v).at(i);
      if (ans.at(u) != -1) {
        continue;
      } else {
        ans.at(u) = ((ans.at(v) + w) % 2);
        q.push(u);
      }
    }
  }

  rep(i, n) {
    cout << ans.at(i) << endl;
  }
  return 0;
}