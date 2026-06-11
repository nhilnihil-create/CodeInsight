#include <iostream>

int main() {
  uint32_t A = 0, B = 0, C = 0, X = 0, Y = 0;
  std::cin >> A >> B >> C >> X >> Y;

  uint32_t min_vol = (C * 2 <= A + B) * ((X <= Y) ? X : Y);
  uint32_t price = (X - min_vol) * (C * 2 <= A ? C * 2 : A) +
                   (Y - min_vol) * (C * 2 <= B ? C * 2 : B) + min_vol * C * 2;

  std::cout << price << std::endl;

  return 0;
}