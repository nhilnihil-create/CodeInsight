#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
long long ans,m,a[500005];
int main()
{
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i]=a[i-1]+a[i];
	ans=1000000000000000000ll;
	for (int i=1;i<=n;i++)
	{
		long long s=0;
		for (int j=n,x=1;j>=1;j-=i,x++)
		{
			int k=max(j-i+1,1);
			if (j==n) s=min(s+2ll*(a[j]-a[k-1]),1000000000000000000ll);
			s=min(s+(long long)(x+x+1)*(a[j]-a[k-1]),1000000000000000000ll);
		}
		s=min(s+m*(i+n),1000000000000000000ll);
		ans=min(ans,s);
	}
	printf("%lld\n",ans);
	return 0;
}
