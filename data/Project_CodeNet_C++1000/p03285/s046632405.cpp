#include <iostream>

int main()
{
  int N;
  std::cin >> N;

  constexpr int CAKE = 4;
  constexpr int DONUTS = 7;

  int n_cake = (100 + CAKE - 1) / CAKE;

  bool can = false;
  for(int c=0; c<=n_cake; c++) {
    if(c * CAKE <= N && (N - c * CAKE) % DONUTS == 0) {
      // std::cout << "c = " << c << " d = " << (N - c * CAKE) / DONUTS << std::endl;
      can = true;
      goto END;
    }
  }

END:
  std::cout << (can ? "Yes" : "No") << std::endl;

  return 0;
}
