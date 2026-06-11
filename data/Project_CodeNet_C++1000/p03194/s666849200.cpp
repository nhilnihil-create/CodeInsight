#include <iostream>
#include <map>
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
  if (p > 1) {
    m[p] = 1;
  }
  uint64_t ans = 1;
  for (auto&& e : m) {
    if (e.second >= n) {
      for (uint64_t i = 0; i < e.second / n; i++) {
	ans *= e.first;
      }
    }
  }
  cout << ans << endl;
}
