#include <stdio.h>

int main()
{
int a[1000];
int m,n,x,cnt=0,cntt=0,i;
scanf("%d %d %d",&m,&n,&x);

for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

for(i=0;i<n;i++)
{
if(a[i]<x)
{
cnt++;
}
else
cntt++;
}

if(cnt>=cntt)
{
printf("%d\n",cntt);
}
else
printf("%d\n",cnt);;

return 0;
}   