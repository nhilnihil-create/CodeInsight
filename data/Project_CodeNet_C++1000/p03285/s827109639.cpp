#include <iostream>

int main() {
  int N;
  std::cin >> N;

  // p is short for price, n is short for number
  // n_cakes * p_cakes + n_doughnuts * p_doughnuts = N
  const int p_cakes = 4, p_doughnuts = 7;

  bool found = false;
  for (int n_cakes = 0; n_cakes <= (N / 4); n_cakes++)
    for (int n_doughnuts = 0; n_doughnuts <= (N / 7); n_doughnuts++)
      if (p_cakes * n_cakes + p_doughnuts * n_doughnuts == N) found = true;

  if (found)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;

  return 0;
}
