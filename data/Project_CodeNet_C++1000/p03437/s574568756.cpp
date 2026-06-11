#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, y;
  cin >> x >> y;

  if (x == y || y == 1 || x % y == 0) {
    cout << -1 << endl;
  } else {
    cout << x << endl;
  }
}