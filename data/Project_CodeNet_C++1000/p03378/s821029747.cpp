#include <bits/stdc++.h>

int main(){
  int N, M, X, A[100], left, right;
  left = 0;
  right = 0;
  std::cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    std::cin >> A[i];
    if (A[i] < X) {
      left += 1;
    }
    else {
      right += 1;
    }
  }
  std::cout << std::min(left, right) << std::endl;
}