#include<stdio.h>
int main(void)
{
  int n,y,i,j,l,f=0,x,k,z;
  scanf("%d%d",&n,&y);
  for(i=0;i<n+1;i++){
    for(j=0;j+i<n+1;j++){
      l=n-(i+j);
        if(y==i*1000+j*5000+l*10000&&i+j+l==n){
        	printf("%d %d %d\n",l,j,i);
          return 0;
        }
      }
    }
    printf("-1 -1 -1\n");
  return 0;
}
        
    
