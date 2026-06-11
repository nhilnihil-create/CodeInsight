#include<stdio.h>
int main(){
 int kt,kecil;
 scanf("%d %d", &kt, &kecil);
char hrf[kt+5];
 
 scanf("%s",hrf);
 hrf[kecil -1] += 32;
 printf("%s",hrf);
  
  return 0;
}