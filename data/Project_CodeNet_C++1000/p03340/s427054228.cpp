#include <cstdio>
using namespace std;
const long long NR=210000;
long long n,l,r,mid,ans,a[NR],s1[NR],s2[NR];
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s1[i]=s1[i-1]+a[i];
		s2[i]=s2[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		l=i;
		r=n+1;
		while((r-l)>1)
		{
			mid=(l+r)>>1;
			if((s1[mid]-s1[i-1])==(s2[mid]^s2[i-1]))
			{
				l=mid; 
			}
			else
			{
				r=mid;
			}
		}
		ans+=(l-i+1);
	}
	printf("%lld",ans);
	return 0;
}