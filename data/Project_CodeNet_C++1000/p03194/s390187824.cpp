#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  long long int n,p;
  scanf("%lld",&n);
  scanf("%lld",&p);
  //printf("CHECKED\n");
  long long int ptemp = p;
  long long int prime = 2;
  long long int ans = 1;
  long long int anstemp = 0;
  while(ptemp > 1) {
    anstemp = 0;
    while(ptemp%prime == 0) {
      ptemp = ptemp/prime;
      //printf("%lld\n",ptemp);
      anstemp++;
    }
    while(anstemp >= n) {
      ans = ans * prime;
      anstemp -= n;
    }
    if(prime==2) {
      prime = 3;
    } else {
      if(prime * prime > ptemp) {
        prime = ptemp;
      } else {
        prime += 2;
      }
    }
    //printf("prime = %lld\n",prime);
  }
  printf("%lld\n",ans);
  return 0;
}
