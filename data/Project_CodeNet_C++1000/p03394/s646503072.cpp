#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 30000;

int main() {
  int n;
  std::cin >> n;
  if(n == 3) {
    std::cout << 2 << " " << 5 << " " << 63;
    return 0;
  }
  std::cout << 3 << " " << 9 << " ";
  n -= 2;
  for(int i = 0; i < nmax; i += 6) {
    if(1 < n) {
      n -= 2;
      std::cout << i + 2 << " " << i + 4 << " ";
    }
  }
  for(int i = 12; i < nmax; i += 12) {
    if(1 < n) {
      n -= 2;
      std::cout << i + 3 << " " << i + 9 << " ";
    }
  }
  for(int i = 6; i <= nmax; i += 6) {
    if(1 <= n) {
      n -= 1;
      std::cout << i << " "; 
    }
  }
  return 0;
}
