#include <iostream>
#include <algorithm>
#include <cstdio>

long long int N;
long long int A[100000 + 1], B[100000 + 1], C[100000 + 1];
long long int p[100000 + 1];

int main() {
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
  }
  for (int i = 1; i <= N; i++) {
    std::cin >> B[i];
  }
  for (int i = 1; i <= N; i++) {
    std::cin >> C[i];
  }

  std::sort(A, A + (N + 1));
  std::sort(B, B + (N + 1));

  for (int i = 1; i <= N; i++) {
    long long int *iter = std::lower_bound(A, A + (N + 1), B[i]);

    p[i] = (iter - 1 - A);

    p[i] += p[i - 1];
  }

  long long int ans = 0;
  for (int i = 1; i <= N; i++) {
    long long int *iter = std::lower_bound(B, B + (N + 1), C[i]);
    if (iter > B) {
      ans += p[iter - 1 - B];
    }
  }

  std::cout << ans << std::endl;

  return 0;
}