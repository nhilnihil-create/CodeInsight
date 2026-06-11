#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, a, b;
  cin >> n >> a >> b;
  if (a + b > n + 1 || 1LL * a * b < n) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> res(n);
  iota(res.begin(), res.end(), 1);

  int num = n - a, iter = 0, leng;
  while (num > 0) {
    leng = min(num, b - 1);
    reverse(res.begin() + iter, res.begin() + iter + leng + 1);
    iter += leng + 1;
    num -= leng;
  }

  for (auto i : res) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}
