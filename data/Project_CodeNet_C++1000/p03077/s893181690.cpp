#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long n;
  vector<long long> as(5);
  cin >> n;
  long long bottleneck = 2 * 1'000'000'000'000'000;

  for (long long &a : as) {
    cin >> a;
    bottleneck = min(bottleneck, a);
  }

  long long num = n / bottleneck + (n % bottleneck == 0 ? 0 : 1);
  long long result = num + 4;

  std::cout << result << std::endl;
  return 0;
}