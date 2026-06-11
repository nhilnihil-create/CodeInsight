#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=200010;
const int inf=2147483647;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
int n,f[Maxn],g[Maxn];LL sum[Maxn],a[Maxn],tmp[4];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
	f[2]=1;
	for(int i=3;i<n-1;i++)
	{
		f[i]=f[i-1];
		while(abs(sum[i]-2LL*sum[f[i]+1])<=abs(sum[i]-2LL*sum[f[i]]))++f[i];
	}
//	return 0;
	g[n-1]=n;
	for(int i=n-2;i>2;i--)
	{
		g[i]=g[i+1];
//		printf("%d %d\n",i,g[i]);
		while(abs(sum[n]-2LL*sum[g[i]-2]+sum[i-1])<=abs(sum[n]-2LL*sum[g[i]-1]+sum[i-1]))--g[i];
	}
	LL ans=7e18;
	for(int i=2;i<n;i++)
	{
		tmp[0]=sum[i]-sum[f[i]];
		tmp[1]=sum[f[i]];
		tmp[2]=sum[n]-sum[g[i+1]-1];
		tmp[3]=sum[g[i+1]-1]-sum[i];
		sort(tmp,tmp+4);
		ans=min(ans,tmp[3]-tmp[0]);
//		ans=min(ans,abs(sum[i]-2LL*sum[f[i]])+abs(sum[n]-2LL*sum[g[i+1]-1]+sum[i]));
	}
	printf("%lld",ans);
}