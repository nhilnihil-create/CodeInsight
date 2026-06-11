#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b, c, d;
  d = n % 10;
  c = n % 100 / 10;
  b = n % 1000 / 100;
  a = n / 1000;
  if (b == c) {
    if (a == b || c == d) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "No" << endl;
  }
}