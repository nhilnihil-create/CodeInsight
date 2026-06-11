#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}
template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

constexpr int DEBUG = 0;

int Solve() {
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];

  auto is_valid = [&](int k) -> bool {
    if (k == 1) {
      for (int i = 0; i < n - 1; i++) {
        if (xs[i] >= xs[i + 1]) return false;
      }
      return true;
    }

    map<int, int> current;
    for (int i = 1; i < n; i++) {
      if (xs[i] <= xs[i - 1]) {
        while (!current.empty() && current.rbegin()->first > xs[i]) {
          current.erase(current.rbegin()->first);
        }
        current[xs[i]]++;
        int x = xs[i];
        for (int x = xs[i]; x >= 1; x--) {
          if (current[x] < k) break;
          current[x] = 0;
          current[x - 1]++;
        }
        if (current[0] > 0) return false;
      }
    }
    return true;
  };
  if (is_valid(1)) return 1;

  int l = 1;
  int r = n;
  while (r - l >= 2) {
    int m = (l + r) / 2;
    if (is_valid(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << Solve() << endl;
}
