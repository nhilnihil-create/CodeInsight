#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> d(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> d[i];
  }
  std::sort(d.begin(), d.end());
  const auto itr = std::unique(d.begin(), d.end());
  std::cout << (itr - d.begin()) << std::endl;
}