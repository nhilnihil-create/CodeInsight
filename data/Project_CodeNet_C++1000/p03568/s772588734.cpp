#include <bits/stdc++.h>

using namespace std;

int dfs(int v, int i, vector<int> &a) {
  if (i == a.size()) {
    return (v % 2 == 0);
  }
  int x = dfs(v * (a[i] - 1), i + 1, a);
  int y = dfs(v * a[i], i + 1, a);
  int z = dfs(v * (a[i] + 1), i + 1, a);
  return x + y + z;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << dfs(1, 0, a) << endl;

  return 0;
}