#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  auto check = [&](int b) {
    map<int, int> s;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] >= a[i + 1]) {
        while (!s.empty() && s.rbegin()->first >= a[i + 1]) {
          s.erase(--s.end());
        }
        for (int j = a[i + 1] - 1; ~j; --j) {
          ++s[j];
          if (s[j] == b) {
            s.erase(j);
          } else {
            break;
          }
          if (!j) {
            return false;
          }
        }
      }
    }
    return true;
  };
  bool flag = true;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] >= a[i + 1]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    puts("1");
    return 0;
  }
  int l = 2, r = n + 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", r);
  return 0;
}