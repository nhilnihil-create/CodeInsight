#include <iostream>
#include <vector>
using namespace std;

const int64_t SIZE = 55556;

vector<int64_t> sieve() {
  vector<int64_t> prime;
  bool composite[SIZE];
  for (int64_t i = 2; i < SIZE; i++) {
    if (!composite[i]) {
      prime.emplace_back(i);
    }
    for (int64_t j = 0; j < prime.size() && i * prime[j] < SIZE; j++) {
      composite[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
  return prime;
}

int main() {
  int n;
  cin >> n;
  auto primes = sieve();
  for (int i = 0, j = 0; j < n; ++i) {
    if (primes[i] % 5 == 1) {
      cout << primes[i] << ' ';
      ++j;
    }
  }
  return 0;
}