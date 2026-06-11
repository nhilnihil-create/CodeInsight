#include <stdio.h>
int main(){
  int a, b, c, d, e, k;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k);

  if( ((a-b)<=k) && ((a-c)<=k) && ((a-d)<=k) && ((a-e)<=k) && ((b-a)<=k) && ((b-c)<=k) && ((b-d)<=k) && ((b-e)<=k) && ((c-a)<=k) && ((c-b<=k)) && ((c-d)<=k) && ((c-e)<=k) && ((d-a)<=k) && ((d-b)<=k) && ((d-c)<=k) && ((d-e)<=k) && ((e-a)<=k) && ((e-b)<=k) && (e-c)<=k && (e-d)<=k)
    printf("Yay!\n");
  else printf(":(\n");

  return 0;
}
