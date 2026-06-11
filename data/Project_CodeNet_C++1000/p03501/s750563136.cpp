#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, x, y;
  cin >> n >> a >> b;
  x = n * a;
  y = b;

  if (x <= y) {
    cout << x << endl;
  }
  else {
    cout << y << endl;
  }
}