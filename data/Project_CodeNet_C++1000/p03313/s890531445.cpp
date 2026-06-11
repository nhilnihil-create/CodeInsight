#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++)
    scanf("%d", &a[i]);
  vector<vector<int>> v(1 << n);
  for (int i = 0; i < (1 << n); i++)
    v[i].push_back(a[i]);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < (1 << n); i++) {
      if (!((i >> j) & 1)) {
        int to = i | (1 << j);
        for (int x : v[i])
          v[to].push_back(x);
        sort(v[to].begin(), v[to].end());
        reverse(v[to].begin(), v[to].end());
        v[to] = {v[to][0], v[to][1]};
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    ans = max(ans, v[i][0] + v[i][1]);
    printf("%d\n", ans);
  }
  return 0;
}