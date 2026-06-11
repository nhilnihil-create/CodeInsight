#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

long long power(long long a, long long b) {
  long long mult = a;
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans = (ans * mult) % mod;
    }
    mult = (mult * mult) % mod;
    b >>= 1;
  }
  return ans;
}

long long inv(long long n) {
  long long rest = mod - 2;
  return power(n, rest);
}

int main() {
  long long N;
  cin >> N;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<long long> weight(N);
  weight[0] = 0;
  for (int i = 1; i < N; i++) {
    weight[i] = (weight[i - 1] + inv(i + 1)) % mod;
  }

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans = (ans + A[i] * (1 + weight[N - i - 1] + weight[i])) % mod;
  }

  for (int i = 0; i < N; i++) {
    ans = (ans * (i + 1)) % mod;
  }

  cout << ans << endl;

  return 0;
}