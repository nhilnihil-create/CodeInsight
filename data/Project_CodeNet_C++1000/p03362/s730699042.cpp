#include <bits/stdc++.h>
#define M 55555
using namespace std;
vector<int> getPrimes(int n) {
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;
  vector<int> primes;
  for (long long i = 2; i * i <= n; i++)
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i)
        prime[j] = false;
    }
  for (int i = 0; i <= n; i++) {
    if (prime[i]) primes.push_back(i);
  }
  return primes;
}
int main() {
  int n = 0, N;
  cin >> N;
  for (int x : getPrimes(M)) {
    if (x%5 == 1) cout << x << ' ';
    n += x%5 == 1;
    if (n == N) return 0;
  }
}