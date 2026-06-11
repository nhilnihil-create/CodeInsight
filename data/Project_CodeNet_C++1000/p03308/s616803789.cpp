#include <iostream>

int main() {
  // N is the length of integer array
  // 2 <= N <= 100
  int N;
  int A[100] = {0};
  std::cin >> N;

  for (int i = 0; i < N; ++i) std::cin >> A[i];

  int max = A[0], min = A[0];
  for (int i = 0; i < N; ++i) {
    if (A[i] > max) max = A[i];
    if (A[i] < min) min = A[i];
  }

  std::cout << max - min << std::endl;

  return 0;
}
