#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int64_t power(int64_t x, int64_t n) {
  int64_t ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

int64_t rev(int64_t x) {
  return power(x, mod - 2);
}


int main() {
  int N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int64 po = 1;
  for(int i = 1; i <= N; i++) (po *= i) %= mod;

  int64 re[100001] = {};
  for(int i = 0; i < N; i++) re[i] = rev(i + 1);
  for(int i = 1; i < N; i++) (re[i] += re[i - 1]) %= mod;

  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    (ret += A[i] * re[i]) %= mod;
    (ret += A[i] * re[N - i - 1]) %= mod;
    (ret += mod - A[i]) %= mod;
  }
  cout << ret * po % mod << endl;
}
