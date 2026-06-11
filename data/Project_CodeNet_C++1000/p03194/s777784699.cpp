#include <bits/stdc++.h>
using namespace std;
unsigned long long p;
unsigned long long quick(unsigned long long a,unsigned long long b)
{
	if(b==1)
		return a;
	unsigned long long ret=quick(a,b/2);
	if(b%2==1)
		return ret*ret*a;
	return ret*ret;
}
int main()
{
	int n;
	unsigned long long pp=2,ans=1,tmp;
	scanf("%d%lld",&n,&p);
	if(n==1)
	{
		printf("%lld",p);
		return 0;
	}
	while(p!=1)
	{
		tmp=quick(pp,n);
		if(p<tmp||tmp==0)
			break;
		while(p%tmp==0)
		{
			p/=tmp;
			ans*=pp;
			if(p<tmp)
				break;
		}
		pp++;
	}
	printf("%lld",ans);
	return 0;
}