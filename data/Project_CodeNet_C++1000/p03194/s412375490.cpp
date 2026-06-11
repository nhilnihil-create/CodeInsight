#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
  uint64_t n, p;
  cin >> n >> p;
  map<uint64_t, uint64_t> m;
  for (uint64_t i = 2; i * i <= p; i++) {
    while (p % i == 0) {
      m[i]++;
      p /= i;
    }
  }
  m[p] = 1;
  uint64_t ans = 1;
  for (const auto& e : m) {
    ans *= pow(e.first, e.second / n);
  }
  cout << ans << endl;
}
