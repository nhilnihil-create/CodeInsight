#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long q,a,b,p,t,ans,k;
int main()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&a,&b);
		ans=0;
		p=sqrt(a*b-1);
		if (p*p>a*b-1) p--;
		ans=2*p;
		if (p>=a) ans--;
		if (p>=b) ans--;
		if (p*(p+1)>=a*b) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}