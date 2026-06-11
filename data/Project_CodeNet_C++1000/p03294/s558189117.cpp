#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::cout << sum - n << "\n";
  return 0;
}