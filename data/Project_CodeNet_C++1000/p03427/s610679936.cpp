#include <algorithm>
#include <iostream>
#include <vector>

int calc(std::vector<int> a, size_t i, int sum) {
  if (i == 0)
    return a.at(i);
  int x = a.at(i) + calc(a, i - 1, sum);
  a.at(i - 1) -= 1;
  int y = 9 + calc(a, i - 1, sum);
  return std::max(x, y);
}

int main(int argc, char *argv[]) {
  long n;
  std::cin >> n;
  std::vector<int> a;
  while (n >= 1) {
    a.push_back(n % 10);
    n /= 10;
  }
  std::reverse(a.begin(), a.end());

  std::cout << calc(a, a.size() - 1, 0) << std::endl;
}
