#include<bits/stdc++.h>
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(x,y) (x^=y^=x^=y)
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 100005 
int n,m,a[MN],b[MN],c[MN];
int t[MN<<1];
void C(int x){for(;x<MN*2;x+=(x&-x))t[x]++;}
int G(int x){int res=0;for(;x;x-=(x&-x))res+=t[x];return res;}
inline bool check(int x)
{
	ll cnt=0ll;
	register int i;
	for(i=1;i<=n;++i) c[i]=c[i-1]+(a[i]>=x?1:-1);
	memset(t,0,sizeof t);
	for(i=1;i<=n;++i)
	{
		C(c[i-1]+MN);
		cnt+=G(c[i]+MN);
	}
	return cnt*4>=1ll*n*(n+1);
}
int main()
{
	n=read();register int i;
	for(i=1;i<=n;++i) a[i]=b[i]=read();
	std::sort(b+1,b+n+1);
	m=std::unique(b+1,b+n+1)-b-1;
	int l,r,ans;
	for(l=1,r=m,ans=0;l<=r;)
	{
		int mid=l+r>>1;
		if(check(b[mid])) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",b[ans]);
}