#include <bits/stdc++.h>
using namespace std;

int n, k, q;

int split_by(int x, const vector<int> &a) {
  vector<vector<int>> v;
  vector<int> cur;
  for (int i = 0; i < int(a.size()); ++i) {
    if (a[i] < x) {
      v.push_back(cur);
      cur.clear();
    } else {
      cur.push_back(a[i]);
    }
  }
  v.push_back(cur);
  vector<int> candidates;
  for (auto z : v) {
    sort(z.begin(), z.end());
    for (int i = 0; i + k - 1 < int(z.size()); ++i)
      candidates.push_back(z[i]);
  }
  sort(candidates.begin(), candidates.end());
  return (q - 1 < int(candidates.size()) ? candidates[q - 1] - x : int(2e9));
}

int main() {
  scanf("%d %d %d", &n, &k, &q);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<int> b(a);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int ans = -1;
  for (int x : b) {
    int z = split_by(x, a);
    if (ans == -1 || ans > z)
      ans = z;
  }
  printf("%d\n", ans);
  return 0;
}