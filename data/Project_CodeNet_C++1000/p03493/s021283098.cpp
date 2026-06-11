#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a;
  b = a / 100;
  c = (a - b * 100) / 10;
  cout << b + c + a - b * 100 - c * 10 << endl;
}