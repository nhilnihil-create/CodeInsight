#include<iostream>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int price;
  bool should_get_c = C * 2 < (A + B);
  if (should_get_c) {
    int rest = X - Y;
    if (rest < 0) rest = -rest;
    int c_to_get;
    bool should_still_get_c = 0;
    if (X < Y) {
      c_to_get = Y - rest;
      X = 0;
      Y = rest;
      should_still_get_c = C * 2 < B;
    } else {
      c_to_get = X - rest;
      X = rest;
      Y = 0;
      should_still_get_c = C * 2 < A;
    }
    c_to_get *= 2;
    if (should_still_get_c) {
      c_to_get += rest * 2;
      X = 0, Y =0;
    }
    price = C * c_to_get + A * X + B * Y;
  } else {
    price = A * X + B * Y;
  }
  cout << price << endl;
  return 0;
}
