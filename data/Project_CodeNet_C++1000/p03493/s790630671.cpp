#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c, a_1;
  cin >> a;
  b = a % 10;
  c = c + b;
  a_1 = (a - b) / 10;
  b = (a_1) % 10;
  c = c + b;
  b = ((a_1 - b) / 10) % 10;
  c = c + b;
  cout << c << endl;
}

