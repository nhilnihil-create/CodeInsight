#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, a, b, c;
  cin >> A;

  a = A / 100;
  b = (A - 100 * a) /10;
  c = (A - 100 * a - 10 * b);
  cout << a + b + c << endl;
}