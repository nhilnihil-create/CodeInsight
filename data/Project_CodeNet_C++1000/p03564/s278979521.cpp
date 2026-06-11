#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, k, x;
  cin >> n >> k;
  x = 1;

  // ここにプログラムを追記
  rep (i, n) {
    if ((x * 2) < (x + k)) {
      x *= 2;
    }
    else {
      x += k;
    }
  }
  cout << x << endl;
}
