#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const long long NR=210000;
long long a[NR],n;
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long l=1,r=1,tmp=0,sum=0;
	while(r<=n)
	{
		while((a[r]^tmp)==(a[r]+tmp)&&r<=n)
		{
			tmp^=a[r];
			r++;
		}
		if(r!=n+1)
		{
			sum+=r-l;
		}
		else
		{
			sum+=(r-l)*(r-l+1)/2;
		}
		tmp^=a[l];
		l++;
	}
	printf("%lld",sum);
	return 0;
}