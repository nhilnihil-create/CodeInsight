#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#define DEBUG

int main(void){
  char buf[512] = { 0 };
  int N;
  int A[2][100] = { { 0 } };
  char *tok = NULL;
  
  //N読み込み
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &N);
  
  // 配列読み込み
  for(int i = 0; i < 2; i++){
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
    
    tok = strtok(buf, " ");
    for(int j = 0; j < N; j++){
      A[i][j] = atoi(tok);
      tok = strtok(NULL, " ");
    }
  }
 
#ifdef DEBUG
  //配列debug
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < N; j++){
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
#endif
  
  int max_sum = -1;
  for(int j = 0; j < N; j++){
    int sum_tmp = 0;
    int j_tmp = 0;    
    for(j_tmp = 0; j_tmp <= j; j_tmp++){
      sum_tmp += A[0][j_tmp];
    }
    
    sum_tmp += A[1][j_tmp - 1];
    
    for(; j_tmp < N; j_tmp++){
      sum_tmp += A[1][j_tmp];
    }
    if(max_sum < sum_tmp) max_sum = sum_tmp;
  }
  
  printf("%d\n", max_sum);
  
  return 0;
}