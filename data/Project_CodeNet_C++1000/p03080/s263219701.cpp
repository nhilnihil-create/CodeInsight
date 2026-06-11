#include <stdio.h>

int main(void)
{
  int N;
  char s[100];
  int count = 0;
  scanf("%d",&N);
  for(int i = 0;i < N;i++){
    scanf("%s",&s[i]);
  }
  for(int i = 0;i < N;i++){
    if(s[i] == 'R'){
      count++;
    }
    else{
      count--;
    }
  }
  if(count > 0){
    printf("Yes");
  }
  else{
    printf("No");
  }
  return 0;
}
