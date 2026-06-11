#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int checkMove(int time, int x, int y){
  
  if(time == 0){
    if(x == 0 && y == 0) return 0;
    else return -1;
  }
  
  if(x == 0 && y == 0){
    if(time % 2 == 0) return 0;
    else return -1;
  }
  
  int rc = -1;
  if(x > 0){
  	rc = checkMove(time - 1, x - 1, y);
  	if(rc == 0) return rc;
  }
  else if(x < 0){
  	rc = checkMove(time - 1, x + 1, y);
  	if(rc == 0) return rc;
  }
  else if(y > 0){
  	rc = checkMove(time - 1, x, y - 1);
  	if(rc == 0) return rc;
  }
  else{
  	rc = checkMove(time - 1, x, y + 1);
  	if(rc == 0) return rc;   
  }
  
  return rc;
}

int main(void){
  char buf[32] = { 0 };
  int N;
  int x[131072] = { 0 };
  int y[131072] = { 0 };
  int t[131072] = { 0 };
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &N);
  
  for(int i = 1; i < N + 1; i++){
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
  	sscanf(buf, "%d %d %d", &t[i], &x[i], &y[i]);
  }
  
  //for(int i = 0; i < N + 1; i++) printf("%d %d %d\n", t[i], x[i], y[i]);
  
  int rc = 0;
  for(int i = 1; i < N + 1; i++){
    rc = checkMove(t[i] - t[i-1], x[i] - x[i-1], y[i] - y[i-1]);
    if(rc != 0) break;
  }
  
  if(rc != 0) printf("No\n");
  else printf("Yes\n");
  
  return 0;
}
