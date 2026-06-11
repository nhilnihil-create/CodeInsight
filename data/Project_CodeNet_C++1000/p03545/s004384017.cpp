#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  char buf[16] = { 0 };
  int num[4];
  char numstr;
  int calc[8][3] = {{1,1,1}, {1,1,-1}, {1,-1,1}, {-1,1,1}, 
                        {1,-1,-1}, {-1,1,-1}, {-1,-1,1},{-1,-1,-1}};
  
  fgets(buf, sizeof(buf), stdin);
  for(int i = 0; i < 4; i++){
    numstr = buf[i];
    num[i] = atoi(&numstr);
  }
  
  int i;
  int ans = 0;
  for(i = 0; i < 8; i++){
    ans = num[0] + calc[i][0]*num[1] + calc[i][1]*num[2] + calc[i][2]*num[3];
    if(ans == 7) break;
  }
  
  if( ans != 7 ) return 0; 
  printf("%d", num[0]);
  for(int j = 0; j < 3; j++){
    if(calc[i][j] > 0) printf("+");
    else printf("-");
    printf("%d", num[j+1]);
  }
  printf("=7\n");
  
  return 0;
}