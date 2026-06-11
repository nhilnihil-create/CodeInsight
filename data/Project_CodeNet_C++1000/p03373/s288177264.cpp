#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int D = 2*C;
  
  long long a, b, c;
  a = A*X + B*Y;
  if (X > Y) {
    b = D*Y + A*(X - Y);
    c = D*X;
  } else {
    b = D*X + B*(Y - X);
    c = D*Y;
  }
  
  if (a < b) {
    if (a < c) {
      cout << a << endl;
    } else {
      cout << c << endl;
    }
  } else {
    if (b < c) {
      cout << b << endl;
    } else {
      cout << c << endl;
    }
  }
  
}