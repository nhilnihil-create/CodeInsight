#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, k;
  cin >> a >> b >> k;
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0) {
      if (a % 2 == 1) a--;
      b += a / 2;
      a -= a / 2;
    } else {
      if (b % 2 == 1) b--;
      a += b / 2;
      b -= b / 2;
    }
  }
  cout << a << " " << b << endl;
}