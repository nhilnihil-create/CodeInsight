#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  char buf[16] = { 0 };
  int N;
  char *str = NULL;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &N);
  
  str = (char*)malloc(sizeof(char) * (N + 2));
  fgets(str, sizeof(char) * (N + 2), stdin);
  
  int count = 0;
  for(int i = 1; i < N; i++){
    if(str[i] == 'E') count++;
  }
  int min = count;
  int count_tmp = count;
  for(int i = 1; i < N; i++){
    if(str[i] == 'E') count_tmp--;
    if(str[i-1] == 'W') count_tmp++;
    if(count_tmp < min) min = count_tmp;
  }
  
  printf("%d\n", min);
  
  free(str);
  return 0;
}
