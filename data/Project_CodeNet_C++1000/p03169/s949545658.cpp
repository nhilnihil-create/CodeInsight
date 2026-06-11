#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

template <class T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &vec) {
  for (auto val : vec) {
    if (std::is_fundamental<T>::value)
      stream << " " << val;
    else
      stream << std::endl << val;
  }
  return stream;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i)
    std::cin >> a[i];

  std::vector<std::vector<std::vector<double>>> dp(
      N + 3,
      std::vector<std::vector<double>>(N + 3, std::vector<double>(N + 3, 0.0)));

  std::function<double(int, int, int)> rec = [&](int x, int y, int z) {
    if (dp[x][y][z] > 0.0)
      return dp[x][y][z];
    if (x == 0 && y == 0 && z == 0)
      return dp[x][y][z] = 0.0;
    double res = 0.0;
    if (x > 0)
      res += rec(x - 1, y, z) * x;
    if (y > 0)
      res += rec(x + 1, y - 1, z) * y;
    if (z > 0)
      res += rec(x, y + 1, z - 1) * z;
    res += N;
    res /= x + y + z;
    return dp[x][y][z] = res;
  };

  std::array<int, 3> c{0, 0, 0};
  for (int i = 0; i < N; ++i)
    c[a[i] - 1] += 1;
  double res = rec(c[0], c[1], c[2]);

  std::cout << std::setprecision(12);
  std::cout << res << std::endl;
}
