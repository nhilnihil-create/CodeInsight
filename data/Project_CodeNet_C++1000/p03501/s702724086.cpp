#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, x;
  cin >> n >> a >> b;
  x = a * n;
  if (x >= b) {
    cout << b << endl;
  }
  if (x < b) {
    cout << x << endl;
  }
}