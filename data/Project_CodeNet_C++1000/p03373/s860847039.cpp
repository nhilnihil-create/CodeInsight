#include <bits/stdc++.h>
using namespace std;


int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int price = 0;
  int diff = abs(X - Y);
  if(2 * C < A + B) {
    price += min(X, Y) * 2 * C;
    if(X > Y) {
      if(A >= 2 * C) price += diff * 2 * C;
      else price += diff * A;
    }
    if(X < Y) {
      if(B >= 2 * C) price += diff * 2 * C;
      else price += diff * B;
    }
  } else {
    price = A * X + B * Y;
  }

  cout << price << "\n";
}