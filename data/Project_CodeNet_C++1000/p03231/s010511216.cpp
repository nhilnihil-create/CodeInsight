#include <iostream>
#include <map>
using namespace std;

map<int64_t, int> prime_factor(int64_t n) {
  map<int64_t, int> ret;
  for (int64_t i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

int64_t lcm(int64_t n, int64_t m) {
  map<int64_t, int> n_prime = prime_factor(n);
  map<int64_t, int> m_prime = prime_factor(m);
  for (auto& prime : m_prime) {
    n_prime[prime.first] = max(n_prime[prime.first], prime.second);
  }
  int64_t ret = 1;
  for (auto& prime : n_prime) {
    for (int i = 0; i < prime.second; ++i) ret *= prime.first;
  }
  return ret;
}

int main(void) {
  int64_t N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  if (M < N) {
    swap(N, M);
    swap(S, T);
  }

  int64_t L = lcm(N, M);
  int64_t LN = L / N;
  int64_t LM = L / M;

  map<int, char> parse;
  for (int i = 0; i < N; ++i) {
    int idx = i * LN + 1;
    parse[idx] = S[i];
  }
  for (int i = 0; i < M; ++i) {
    int idx = i * LM + 1;
    if (parse.count(idx) && parse[idx] != T[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << L << endl;
  return 0;
}