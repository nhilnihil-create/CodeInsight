#include <iostream>
#define ll long long
#define PER(i, n) for(long long i = (n); i >= (0); --i)

template <typename T> void chmax (T& a, T b) { if (a < b) a = b; }

int main () {
  ll N, Y;
  std::cin >> N >> Y;
  PER(x, Y / 10000) {
      PER(y, (Y - x * 10000) / 5000) {
          ll z = N - x - y;
          if (x * 10000 + y * 5000 + z * 1000 == Y) {
              std::cout << x << " " << y << " " << z << std::endl;
              return 0;
          }
      }
  }
  std::cout << -1 << " " << -1 << " " << -1 << std::endl;
  return 0;
}