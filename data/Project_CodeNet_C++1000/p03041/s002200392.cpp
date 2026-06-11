#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  char S[N + 1];
  scanf("%s", S);
  S[K - 1] = S[K - 1] + 'a' - 'A';
  printf("%s", S);
  return 0;
}