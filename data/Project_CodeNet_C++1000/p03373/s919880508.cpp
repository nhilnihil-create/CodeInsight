#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C, X, Y;
  int price = 0;

  cin >> A >> B >> C >> X >> Y;

  if (X >= Y) {
    if (A + B <= 2 * C) {
      if (A <= 2 * C) price += Y * (A + B) + (X - Y) * A;
      else if (A > 2 * C) price += Y * (A + B) + 2 * (X - Y) * C;
    }
    else if (A + B > 2 * C) {
      if (A <= 2 * C) price += 2 * Y * C + (X - Y) * A;
      else if (A > 2 * C) price += 2 * Y * C + 2 * (X - Y) * C;
    }
  }
  else if (X < Y) {
    if (A + B <= 2 * C) {
      if (B <= 2 * C) price += X * (A + B) + (Y - X) * B;
      else if (B > 2 * C) price += X * (A + B) + 2 * (Y - X) * C;
    }
    else if (A + B > 2 * C) {
      if (B <= 2 * C) price += 2 * X * C + (Y - X) * B;
      else if (B > 2 * C) price += 2 * X * C + 2 * (Y - X) * C;
    }
  }
  
  cout << price << endl;
  
}