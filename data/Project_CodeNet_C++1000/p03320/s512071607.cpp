#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;long long x=0;
	scanf("%d",&k);
	while(k--)
	{
		int y=0,Y,z[20],zn=0;long long i,X,t=1;
		for(i=++x;i;i/=10)y+=z[++zn]=i%10;
		for(X=x,Y=y,i=1;i<=zn;++i)
		{
			X+=(9-z[i])*t;Y+=9-z[i];t*=10;
			if(x*Y>X*y)x=X,y=Y;
		}
		printf("%lld\n",x);
	}
}