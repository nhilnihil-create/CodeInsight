#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n, r;
  cin >> n;
  r = 10000;

  // ここにプログラムを追記
  rep(i, n) {
    int a, x;
    cin >> a;
    x = 0;
    while ((a % 2) == 0) {
      x++;
      a /= 2;
    }
    if (x < r) {
      r = x;
    }
  }
  cout << r << endl;
}
