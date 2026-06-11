#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(long long N, long long K, std::vector<long long> A) {
  ll tmp = N - K;
  tmp = 1 + tmp / (K - 1) + ((tmp % (K - 1) == 0) ? 0 : 1);
  cout << tmp << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, K, std::move(A));
  return 0;
}
