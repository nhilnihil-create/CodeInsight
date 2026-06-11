#include <bits/stdc++.h>
using namespace std;

int main() {
  int x = 0, a = 0, b = 0, c = 0;
  cin >> x;
  a = x/100;
  c = x%2;
  b = x/10 % 2;
  cout << a+b+c << endl;
}