#include<stdio.h>
#include<string.h>

int main(){
  int step = 0, aflag = 0, len = 0;
  char s[51];
  scanf("%s", s);
  
  while(s[len]){
    if(step == 0){
      if(aflag == 0 && s[len] == 'A'){
        aflag = 1;
      } else if(s[len] == 'K'){
        step++;
        aflag = 0;
      } else {
        break;
      }
    } else if(step == 1){
      if(s[len] == 'I'){
        step++;
      } else {
        break;
      }
    } else if(step == 2){
      if(s[len] == 'H'){
        step++;
      } else {
        break;
      }
    } else if(step == 3){
      if(aflag == 0 && s[len] == 'A'){
        aflag = 1;
      } else if(s[len] == 'B'){
        step++;
        aflag = 0;
      } else {
        break;
      }
    } else if(step == 4){
      if(aflag == 0 && s[len] == 'A'){
        aflag = 1;
      } else if(s[len] == 'R'){
        step++;
        aflag = 0;
      } else {
        break;
      }
    } else if(step == 5){
      if(s[len] != 'A' || aflag == 1){
        step++;
      } else if(aflag == 0 && s[len] == 'A'){
        aflag = 1;
      }
    }
    len++;
  }
  
  if(step == 5){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  
  return 0;
}