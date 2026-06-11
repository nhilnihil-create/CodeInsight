#include <stdio.h>

int main()

{

int n,max=-1,sum=0,p,i,j;
int m[1000];

scanf("%d ",&n);

for(i=0;i<n;i++)
{
scanf("%d",&m[i]);
}
for(i=0;i<n;i++)
{
if(m[i]>max)
{
max=m[i];
}
}


for(j=0;j<n;j++)

{
sum=sum+m[j];

}


 p=sum-max;

if(p>max)
{
printf("Yes\n") ;
}
else
printf("No\n");


return 0;
}   