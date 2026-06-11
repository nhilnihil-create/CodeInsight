#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int cnt = 0;
  for (int mm = 1; mm <= 12; ++mm)
    for (int dd = 1; dd <= 31; ++dd) {
      if (mm == dd) ++cnt;
      if (mm == a && dd == b) std::cout << cnt << "\n";
    }
}