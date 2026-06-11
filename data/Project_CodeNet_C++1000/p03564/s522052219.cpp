#include <stdio.h>

int main()
{
  int N, K, output = 1;
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) {
    (output + K > output*2) ? output *= 2 : output += K;
  }
  printf("%d\n", output);
  
  return 0;
}