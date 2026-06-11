#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int r, d, a;
  cin >> r >> d >> a;
  int x = a;
  rep(i, 10) {
    x = r * x - d;
    cout << x << endl;
  }
}