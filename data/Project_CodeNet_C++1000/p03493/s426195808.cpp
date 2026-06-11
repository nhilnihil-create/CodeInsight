#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a;
  b = a / 10;
  c = a / 100;
  cout << a - 9 * (b + c) << endl;
}
