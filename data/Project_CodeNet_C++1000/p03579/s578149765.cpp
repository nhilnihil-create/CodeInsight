#include <bits/stdc++.h>
using namespace std;
using graph = vector<vector<int>>;

bool dfs(const graph &to, vector<int> &color, const int current) {
  for (auto next : to.at(current)) {
    if (color.at(next) && color.at(next) == color.at(current)) return false;
    if (color.at(next)) continue;
    color.at(next) = -color.at(current);
    if (dfs(to, color, next) == false) return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  graph to(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    to.at(a - 1).push_back(b - 1);
    to.at(b - 1).push_back(a - 1);
  }
  vector<int> color(n); // 0:unknown 1:black -1:white
  color.at(0) = 1;
  if (dfs(to, color, 0)) {
    int blacks = 0, whites = 0;
    for (int c : color) {
      if (c == 1) {
        blacks++;
      } else {
        whites++;
      }
    }
    cout << (long) blacks * whites - m << endl;
  } else {
    cout << (long) n * (n - 1) / 2 - m << endl;
  }
}
