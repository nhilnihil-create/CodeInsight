#include <bits/stdc++.h>

int main() {
  int A, B, C, D;
  scanf("%d %d %d %d", &A, &B, &C, &D);
  printf("%d", std::min(A, B) + std::min(C, D));
}
