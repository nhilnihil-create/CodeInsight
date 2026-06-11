#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, A, B, x;
  cin >> a >> b;
  A = a%2;
  B = b%2;
  x = A*B;
  if (x == 0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}
