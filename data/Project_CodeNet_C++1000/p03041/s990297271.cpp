#include<stdio.h>
#include<string.h>
 
int main() {
  int K, N;
  scanf("%d %d", &N, &K);
  char S[100];
  scanf("%s", S);
  S[K-1] += 32;
  printf("%s", S);
}
  