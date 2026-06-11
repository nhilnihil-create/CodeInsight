#include <stdio.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  char S[N + 1];
  scanf("%s", S);

  for(int i = 0; i < N; i++) {
    if(i == K - 1) {
      printf("%c", S[i] + 'a' - 'A');
    }
    else {
      printf("%c", S[i]);
    }
  }
  return 0;
}