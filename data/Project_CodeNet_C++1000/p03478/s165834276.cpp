#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    int i2 = i;
    vector<int> x;
    while (i2 > 0) {
      x.push_back(i2 % 10);
      i2 /= 10;
    }
    int sum = 0;
    for (int j : x) {
      sum += j;
    }
    if (sum >= a && sum <= b) {
      res += i;
    }
  }
  cout << res << endl;
  return 0;
}
