#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> cnts(N + 1, 0);
  for (int i = 2; i < N + 1; i++) {
    int n = i;
    for (int j = 2; j * j < n + 1; j++) {
      while (n % j == 0) {
        cnts[j]++;
        n /= j;
      }
    }
    if (n > 1) cnts[n]++;
  }
  auto f = [cnts](int x) {
    int res = 0;
    for (auto cnt : cnts) {
      if (x - 1 <= cnt) res++;
    }
    return res;
  };
  // (1, 75), (5, 15), (3, 5, 5), (3, 25)
  int res = 0;
  res += f(75);
  res += f(15) * (f(5) - 1);
  res += f(5) * (f(5) - 1) * (f(3) - 2) / 2;
  res += f(25) * (f(3) - 1);
  cout << res << '\n';
  return 0;
}
