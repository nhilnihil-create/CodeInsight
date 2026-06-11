#include<iostream>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if (A + B <= C * 2) cout << A * X + B * Y << endl;
  else if (X < Y) {
    int price = X * C * 2;
    if (B < C * 2) price += (Y - X) * B;
    else price += (Y - X) * C * 2;
    cout << price << endl;
  } else {
    int price = Y * C * 2;
    if (A < C * 2) price += (X - Y) * A;
    else price += (X - Y) * C * 2;
    cout << price << endl;
  }
}