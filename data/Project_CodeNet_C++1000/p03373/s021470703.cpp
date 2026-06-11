#include <bits/stdc++.h>
#define int long long

int sumofdigits(int x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

void PrintMap(std::map<int, int>& m) {
  for (auto iter: m) {
    std::cout << iter.first << " => " << iter.second << "\n";
  }
}

signed main() {
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;
  
  int total = 0;
  if (2 * c < a + b) {
    if (x < y) {
      total += x * (2 * c);
      if (b < 2 * c) {
        total += (y - x) * b;
      } else {
        total += (y - x) * (2 * c);
      }
    } else {
      total += y * (2 * c);
      if (a < 2 * c) {
        total += (x - y) * a;
      } else {
        total += (x - y) * (2 * c);
      }
    }
  } else {
    total = a * x + b * y;
  }
  
  std::cout << total << '\n';
  
  return 0;
}