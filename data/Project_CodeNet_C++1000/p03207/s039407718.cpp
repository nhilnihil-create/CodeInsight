#include<stdio.h>
int main() {
int N,i,sum=0,highest=0;
scanf("%d",&N);
for(i=1;i<=N;i++)
{
  int d;
  scanf("%d",&d);    
  sum=sum+d;
  if(highest<d) 
  {
    highest=d;
  }
  else 
  {
   highest=highest;
  }
}
 sum=sum-(highest/2);
 printf("%d",sum);
    return 0;
    }