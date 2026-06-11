#include <stdio.h>

int main(void){
  int n, i;
  int flg=1;
  int count=0;
  int ans=0;
  long a[200];


  scanf("%d", &n);
  for (i=0; i<n; i++){
    scanf("%ld",&a[i]);
  }
  /*
  for (i=0; i<n; i++){
    printf("a[%d]=%ld\n",i,a[i]);
  }
  */
  while(flg==1){
    count=0;
    for (i=0; i<n;i++){
      if (a[i]%2==0){
        count++;
        //printf("OK: a[%d]=%ld, count = %d\n",i,a[i], count);
      }
    }
    if (count==n){
      for (i=0; i<n;i++){
        a[i]=a[i]/2;
        //printf("OK: a'[%d]=%ld\n",i,a[i]);
      }
      ans++;
    }
    else{
      flg=0;
    }
  }

  printf("%d\n",ans);
  return(0);
}

