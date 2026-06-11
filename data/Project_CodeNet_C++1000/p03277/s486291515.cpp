#include <bits/stdc++.h>
#define lowbit(x) (x& -x)
#define oo 0x7fffffff
using namespace std;
const int MAXN=100010;
int bit[MAXN<<1],a[MAXN];
int n;
inline void add(int x,int k)
{
	for(;x<=2*n;x+=lowbit(x))
		bit[x]+=k;
}
int getsum(int x)
{
	int s=0;
	for(;x;x-=lowbit(x))
		s+=bit[x];
	return s;
}
int check(int mid)
{
	for(int i=1;i<=2*n;++i)
		bit[i]=0;
	long long tot=0,sum=0;
	add(n,1);
	for(int i=1;i<=n;++i)
		{
			sum+=mid<=a[i]?1:-1;
			tot+=getsum(sum+n);
			add(sum+n,1);
		}
	return tot>=1ll*n*(n+1)/4;
}
int main()
{
	scanf("%d",&n);
	int mmax=-oo,mmin=oo;
	for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			mmin=min(mmin,a[i]);
			mmax=max(mmax,a[i]);
		}
	int l=mmin,r=mmax;
	while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(mid))
				l=mid;
			else
				r=mid-1;
		}
	printf("%d",l);
    return 0;
}