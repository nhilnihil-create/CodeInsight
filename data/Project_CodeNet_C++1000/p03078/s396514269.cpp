#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int k;
long long a[1005],b[1005],c[1005];
long long sum[1005*1005];
long long ans[3005*1005];
long long cnt;

bool cmp (long long x , long long y)
{
	return x > y;
}

int main()
{
	scanf("%d%d%d%d",&x,&y,&z,&k);
	for(int i=1;i<=x;++i)
	    scanf("%lld",&a[i]);
	for(int i=1;i<=y;++i)
	    scanf("%lld",&b[i]);
	for(int i=1;i<=x;++i)
		for(int j=1;j<=y;++j)
		   sum[++cnt]=a[i]+b[j];
	for(int i=1;i<=z;++i)
	    scanf("%lld",&c[i]);
	sort(sum+1,sum+1+cnt,cmp);
	long long now=0;
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=z;++j)
		    ans[++now]=sum[i] + c[j];
	}
	sort(ans+1,ans+1+now,cmp);
	for(int i=1;i<=k;++i)
	   printf("%lld\n",ans[i]);
	return 0;
}