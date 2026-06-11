#include <iostream>

int main() {
  uint32_t A = 0, B = 0, C = 0, X = 0, Y = 0;
  std::cin >> A >> B >> C >> X >> Y;

  uint32_t price = 0;
  uint32_t min_vol = (X <= Y) ? X : Y;
  if (C * 2 <= A + B) {
    price += min_vol * C * 2;
    X -= min_vol;
    Y -= min_vol;
  }
  price += X * (C * 2 <= A ? C * 2 : A) + Y * (C * 2 <= B ? C * 2 : B);

  std::cout << price << std::endl;

  return 0;
}