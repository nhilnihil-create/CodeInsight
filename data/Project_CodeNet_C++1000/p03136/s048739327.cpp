#include<stdio.h>
int main()
{

int n,C,i,sum=0,max;
scanf("%d",&n);
int A[n];
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
sum=sum+A[i]; 
}
max=A[0];
for(i=1;i<n;i++)
{
  if(max<A[i])
  max=A[i];
}
C=sum-max;
if(C>max) printf("Yes\n");
else printf("No\n");
return 0;

}