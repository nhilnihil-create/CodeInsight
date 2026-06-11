#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<long long, long long> prime_factors(long long n) {
  map<long long, long long> res;
  if (n == 1) {
    res[n] = 1;
    return res;
  }
  for (long long i = 2, _n = n; i * i <= _n + 1; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main() {
  long long N, P;
  cin >> N >> P;
  map<long long, long long> pf = prime_factors(P);

  long long res = 1;

  for (map<long long, long long>::iterator it = pf.begin(), end = pf.end();
       it != end; ++it) {
    long long cnt = it->second / N;
    while (cnt) {
      res *= it->first;
      --cnt;
    }
  }

  cout << res << endl;

  return 0;
}