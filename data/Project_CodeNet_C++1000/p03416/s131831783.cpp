#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a, b, sum;
  cin >> a >> b;
  sum = 0;

  // ここにプログラムを追記
  rep2 (i, a, b+1) {
    int x0, x1, x2, x3, x4;
    x0 = i % 10;
    x1 = (i / 10) % 10;
    x3 = (i / 1000) % 10;
    x4 = (i / 10000);
    if ((x0 == x4) && (x1 == x3)) {
      sum++;
    }
  }
  cout << sum << endl;
}
