#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  vector<int64_t> numbers(9);
  iota(numbers.begin(), numbers.end(), 1);
  auto numlen = [](int64_t n) {
    return to_string(n).size();
  };
  auto dsum = [](int64_t n) {
    int64_t sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  };
  while ((int)numbers.size() < K) {
    int64_t last = numbers.back();
    int64_t bound = last + 1;
    int64_t cans = bound;
    for (int replace = 1; replace < numlen(bound); ++replace) {
      int64_t k = bound;
      for (int d = 0; d < replace; ++d) {
        k /= 10;
      }
      k = max(k, (int64_t)1);
      for (int d = 0; d < replace; ++d) {
        k = k * 10 + 9;
      }
      if (k * dsum(cans) < cans * dsum(k)) {
        cans = k;
      }
    }
    numbers.push_back(cans);
  }
  for (int64_t n : numbers) {
    cout << n << '\n';
  }
  return 0;
}