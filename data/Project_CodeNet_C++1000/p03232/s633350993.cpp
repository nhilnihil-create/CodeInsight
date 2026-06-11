//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define mdn 1000000007
#define N 100010
using namespace std;
int pre[N],suf[N],fac[N],inv[N],n,a[N];
int ksm(int bs,int mi)
{
	int ans=1;
	while(mi)
	{
		if(mi&1)	ans=1ll*ans*bs%mdn;
		bs=1ll*bs*bs%mdn; mi>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	if(n<m)	return 0;
	return 1ll*fac[n]*inv[m]%mdn*inv[n-m]%mdn;
}
int main()
{
	scanf("%d",&n); fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)	fac[i]=1ll*fac[i-1]*i%mdn;
	inv[n]=ksm(fac[n],mdn-2);
	for(int i=n-1;i;i--)	inv[i]=1ll*inv[i+1]*(i+1)%mdn;
	for(int i=0;i<n;i++)
	{
		pre[i]=1ll*fac[n-i-1]*C(n,i+1)%mdn*fac[i]%mdn;
		if(i)	pre[i]=((ll)pre[i]+pre[i-1])%mdn;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=((ll)pre[i-1]+pre[n-i]-pre[0]+mdn)%mdn;
		ans=((ll)ans+1ll*tmp*a[i]%mdn)%mdn;
	}
	printf("%d\n",ans);
	return 0;
}