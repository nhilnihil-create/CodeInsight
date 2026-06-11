#include <stdio.h>

int main(void){
  int a, b, c, x, xx;
  int ans=0;

  scanf("%d %d %d", &a,&b,&c);
  scanf("%d", &x);
  
  for (int i=0; i<a+1; i++){
    for (int j=0; j<b+1; j++){
      for (int k=0; k<c+1; k++){
        if (x == i*500 + j*100 + k*50) ans++;
      }
    }
  }

  printf("%d\n",ans);
  return(0);
}

