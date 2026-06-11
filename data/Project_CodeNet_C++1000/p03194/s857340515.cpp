#include<iostream>
#include<map>
using namespace std;

map<long, long> prime_factor(long long n) {
  map <long, long> res;
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

long long mod_pow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}

int main() {
  long long N, P;
  cin >> N >> P;
  map<long, long> mp = prime_factor(P);
  long long ans = 1;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    if (it->second >= N) ans *= mod_pow(it->first, it->second / N);
  }
  cout << ans << endl;
}
