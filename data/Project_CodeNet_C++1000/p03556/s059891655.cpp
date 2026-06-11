#include <iostream>

int main() {
  using namespace std;

  int N;
  std::cin >> N;

  int res = 0;
  for (int i = 1; i * i <= N; i++) {
    res = i * i;
  }

  std::cout << res << std::endl;

  return 0;
}
