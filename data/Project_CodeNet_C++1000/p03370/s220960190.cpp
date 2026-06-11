#include <stdio.h>

int main()

{
long long int m[1000000];

long long int sum =0,q;
int x,i,p,z,o;
scanf("%d %d",&x,&o);

for(i=0;i<x;i++)
{
scanf("%lld",&m[i]);

sum=sum+m[i];

}


q=1000000;
for(i=0;i<x;i++)
{
if(m[i]<q)
{
q=m[i];
}
}

if(o==sum)
{
printf("%d",x);
}
else if(o!=sum)
{
p=o-sum;

z=p/q;

printf("%d",z+x);
}

return 0;
}  