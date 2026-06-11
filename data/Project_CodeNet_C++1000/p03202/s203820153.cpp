#include <bits/stdc++.h>
using namespace std;

bool can(int n, const vector<int> &a, int x) {
  if (x == 1)
    for (int i = 1; i < n; ++i)
      if (a[i] <= a[i - 1])
        return false;
  map<int, int> ma;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1])
      continue;
    int k = a[i];
    auto p = ma.upper_bound(k);
    if (p != ma.end())
      ma.erase(p);
    ++ma[k];
    while (k > 0 && ma[k] == x) {
      ma.erase(k);
      ++ma[--k];
    }
    if (k == 0)
      return false;
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  int low = 0, high = n + 1;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    (can(n, a, mid) ? high : low) = mid;
  }
  printf("%d\n", high);
  return 0;
}