#include <iostream>
#include <string>

int main() {
  int N;
  std::cin >> N;
  int res{0};
  std::string A, B, C;
  std::cin >> A >> B >> C;
  for (int i = 0; i < N; i++) {
    char a{A[i]}, b{B[i]}, c{C[i]};
    if (a == b && b == c)
      continue;
    else if (a != b && b != c && c != a)
      res += 2;
    else
      res++;
  }
  std::cout << res << std::endl;
}