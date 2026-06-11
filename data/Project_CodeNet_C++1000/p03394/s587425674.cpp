#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

template <typename T>
int sz(T &x) {
  return (int)(x.size());
}


int main() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63\n";
    return 0;
  }
  if (n == 4) {
    cout << "2 5 20 63\n";
    return 0;
  }
  if (n == 5) {
    cout << "2 5 20 30 63\n";
    return 0;
  }
  int sum = 0;
  vector<int> a;
  int last = 0;
  for (int i = 2; i <= 30000; ++i) {
    if (i % 2 == 0 || i % 3 == 0) {
      a.push_back(i);
      sum += i;
    }
    last = i;
    if (sz(a) == n) {
      break;
    }
  }
  if (sum % 6 != 0) {
    for (int i = 0; i < sz(a); ++i) {
      int found = 0;
      for (int j = last + 1; j <= last + 12; ++j) {
        if ((sum - a[i] + j) % 6 == 0 && (j % 2 == 0 || j % 3 == 0)) {
          a.erase(a.begin() + i);
          a.push_back(j);
          found = 1;
          break;
        }
      }
      if (found) {
        break;
      }
    }
  }

  for (int i : a) {
    cout << i << " ";
  }
  return 0;
}
