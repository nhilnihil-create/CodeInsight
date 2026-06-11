#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+5;
long long n,a[maxn],p[maxn],sum[maxn];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	//	sum[i]=sum[i-1]+a[i];
	//	p[i]=p[i-1]^a[i];
	}
	long long opt2=0,sum1=0,sum2=0;long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long opt1=i;
		while(opt2<n&&(sum1+a[opt2+1])==(sum2^a[opt2+1]))
		{
			opt2++;
			sum1+=a[opt2];
			sum2^=a[opt2];
		}
		long long tot=opt2-opt1+1;
		sum1-=a[opt1];
		sum2^=a[opt1];
		ans+=tot;
	}
	printf("%lld\n",ans);
	return 0;
}