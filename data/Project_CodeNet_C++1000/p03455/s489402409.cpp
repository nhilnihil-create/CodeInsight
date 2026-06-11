#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 //C
 int main(void) {
 int n, k, i, cou=0, tmp;
 int a,b,c,d,e,f;
 scanf(" %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f);
 for(i=0; i < n; i++){

 }

 }
 */

//B
int main(void) {
  int n, k, i, cou=0, tmp;
  scanf(" %d %d", &n, &k);

  if(n * k % 2 == 0) printf("Even");
  else printf("Odd");
  return 0;
}
