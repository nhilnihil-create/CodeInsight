#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  if (a[0] != 0)
    return 0 * puts("-1");
  for (int i = 0; i < n - 1; ++i)
    if (a[i + 1] - a[i] > 1)
      return 0 * puts("-1");
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ) {
    int j = i + 1;
    while (j < n && a[j] == a[i])
      ++j;
    v.emplace_back(a[i], j - i);
    i = j;
  }
  long long ans = 0;
  for (int i = 0; i < int(v.size()); ) {
    int j = i + 1;
    while (j < int(v.size()) && v[j].first == v[j - 1].first + 1)
      ++j;
    int nx = j;
    --j;
    ans += 1LL * v[j].second * v[j].first;
    --j;
    while (j >= i) {
      --v[j].second;
      ans += 1LL * v[j].second * v[j].first;
      --j;
    }
    i = nx;
  }
  printf("%lld\n", ans);
  return 0;
}