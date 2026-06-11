#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
inline void read(int& x)
{
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
int n,a[maxn],sum[maxn],c[maxn+maxn];

inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int pos)
{
	for(int i=pos;i<=n+100000;i+=lowbit(i)) ++c[i];
}
inline int query(int pos)
{
	int ans=0;
	for(int i=pos;i;i-=lowbit(i)) ans+=c[i];
	return ans;
}

bool check(int x)
{
	sum[0]=0;
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+(a[i]>=x?1:-1);
	memset(c,0,sizeof(c));
	long long ans=0;
	for(int i=0;i<=n;++i)
	{
		ans+=query(sum[i]+100000);
		modify(sum[i]+100000);
	}
	return (ans<<2)>=1ll*n*(n+1);
}
int main()
{
	int l=0x3f3f3f3f,r=-0x3f3f3f3f,mid;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),l=min(l,a[i]),r=max(r,a[i]);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}