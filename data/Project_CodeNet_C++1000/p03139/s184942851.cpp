#include <algorithm>
#include <iostream>
#include <string>

int main() {
  int N, A, B;
  std::cin >> N >> A >> B;

  int maxn{std::min(A, B)};
  int minn{std::max(0, A + B - N)};

  std::cout << maxn << ' ' << minn << std::endl;
}