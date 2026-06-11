#include<stdio.h>
#define N 200005
unsigned long long asum[N],axor[N];
int main()
{
	int n,l=1;
	long long ans=0;
	unsigned long long x;
	scanf("%d",&n);
	asum[0]=0;axor[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		asum[i]=asum[i-1]+x;
		axor[i]=axor[i-1]^x;
	}
	for(int i=1;i<=n;i++)
	{
		while((asum[i]-asum[l-1])!=(axor[i]^axor[l-1]))l++;
        ans=ans+i-l+1;
	}
	printf("%lld\n",ans);
}