#include <stdio.h>      
int main() {
  
  int N; 
  int K;
  char S[52];
  
  scanf("%d %d", &N, &K);getchar();
  scanf("%s", &S);getchar();
  
  int M = K-1;
  S[M] += 32;
  printf("%s\n", S);


  return 0;
}
