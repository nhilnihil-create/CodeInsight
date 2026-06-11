#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, a_100, a_10, a_1;
  cin >> a;
  a_100 = a / 100;
  a_10 = (a - a_100 * 100) / 10;
  a_1 = (a - a_100 * 100 - a_10 * 10) / 1;
  cout << a_100 + a_10 + a_1 << endl;
}