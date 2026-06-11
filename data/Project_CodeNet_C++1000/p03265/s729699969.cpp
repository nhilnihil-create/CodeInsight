#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = c - a; // 4
  int y = d - b; // 3
  cout << c - y;
  cout << " ";
  cout << d + x;
  cout << " ";
  cout << a - y;
  cout << " ";
  cout << b + x;
}