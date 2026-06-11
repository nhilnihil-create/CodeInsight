#include <bits/stdc++.h>
using namespace std;

long long n, a, b;
vector<int> res;

bool solve();

int main() {
  cin >> n >> a >> b;
  if (solve())
    for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
  else
    cout << -1 << endl;
  return 0;
}

bool solve() {
  if (n < a || n < b || a + b - 1 > n || b < (n + a - 1) / a) return 0;
  for (int i = 0; i < a; ++i) res.push_back(n - a + 1 + i);
  --b;
  for (int i = n - a; i > 0;) {
    if (b == i) {
      while (i) res.push_back(i--);
    } else {
      --b;
      long long num = min(i - b, a);
      for (int j = 0; j < num; ++j) res.push_back(i - num + 1 + j);
      i -= num;
    }
  }
  return 1;
}