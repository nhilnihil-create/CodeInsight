#include<stdio.h>

int main(int argc, char *argv[]){

  int n;
  scanf("%d", &n);

  char s[n+1];
  scanf("%s", &s);
  //printf("%s\n", s);
  // s[0], s[1], s[2],..., s[n-2], s[n-1]

  int cnt = 0;
  int i = 0; // reader index
  for(int j=1; j<n; j++){
    //printf("%c\n", s[i]);
    if(s[j] == 'E') cnt++;
  }
  int cnt_min = cnt;

  for(i=1; i<n; i++){
    if(s[i-1] == 'W') cnt++;
    if(s[i] == 'E') cnt--;
    if(cnt < cnt_min){
      cnt_min = cnt;
    }
  }
  printf("%d\n", cnt_min);

  return 0;
}
