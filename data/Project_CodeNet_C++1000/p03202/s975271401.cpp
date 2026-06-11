#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto isOk = [&] (int kinds) {
    int len = 0;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      if (a[i] > len) {
        s.emplace_back(0, a[i] - len);
        len = a[i];
        continue;
      }
      while (len > a[i]) {
        int pop = min(s.back().second, len - a[i]);
        s.back().second -= pop;
        if (s.back().second == 0) s.pop_back();
        len -= pop;
      }
      while (!s.empty() && s.back().first == kinds - 1) {
        len -= s.back().second;
        s.pop_back();
      }
      if (len == 0) {
        return false;
      }
      if (s.back().second == 1) {
        int k = s.back().first;
        s.pop_back();
        s.emplace_back(k + 1, 1);
      } else {
        int k = s.back().first;
        int l = s.back().second;
        s.pop_back();
        s.emplace_back(k, l - 1);
        s.emplace_back(k + 1, 1);
      }
      if (len < a[i]) s.emplace_back(0, a[i] - len);
      len = a[i];
    }
    return true;
  };
  int low = 0, high = n;
  while (high - low > 1) {
    int middle = (low + high) >> 1;
    if (isOk(middle)) high = middle;
    else low = middle;
  }
  cout << high << endl;
  return 0;
}