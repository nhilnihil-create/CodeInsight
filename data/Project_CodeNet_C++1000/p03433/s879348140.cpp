#include <iostream>

#define REP(i, n) for(int i = 0; i < (n); ++i)

int main () {
  int N, A;
  std::cin >> N >> A;
  REP(i, A+1) {
      if ((N - i) % 500 == 0) {
          std::cout << "Yes" << std::endl;
          return 0;
      }
  }
  std::cout << "No" << std::endl;
  return 0;
}