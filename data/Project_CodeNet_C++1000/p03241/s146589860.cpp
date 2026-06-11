#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

template<typename T>
std::map<T, int> prime_factorize(T x) {
  std::map<T, int> primes;
  for (T factor = 2; factor * factor <= x; factor++) {
    if (x % factor == 0) {
      T count = 0;
      while (x % factor == 0) {
          count++;
          x /= factor;
      }
      primes[factor] = count;
    }
  }
  if (x != 1) primes[x] = 1;
  return primes;
}

int N, M;
int main() {
  cin >> N >> M;
  int i = 1, vmax = 1;
  for (; i * i <= M; ++i) {
    if (M % i != 0) continue;
    int x = M / i;
    if (i >= N) {
      vmax = x;
      break;
    }
    if (x >= N) vmax = i;
  }
  cout << vmax << endl;
}
