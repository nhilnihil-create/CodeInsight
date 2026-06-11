#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  std::vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (i < n/2) {
      ans[a[i].second] = a[n/2].first;
    } else {
      ans[a[i].second] = a[n/2-1].first;
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << "\n";
  }
  return 0;
}