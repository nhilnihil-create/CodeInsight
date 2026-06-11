#include<bits/stdc++.h>
typedef long long LL;
#define lowbit(x) (x)&(-(x))
using namespace std;
const int maxn=110000;
const int maxm=210000;
int a[maxn],san[maxn],b[maxn],op[maxn];
int n;
struct BIT
{
	int t[maxm];
	void add(int x,int v)
	{
		for(int i=x;i<=maxm;i+=lowbit(i)) t[i]+=v;
		return;
	}
	int ca(int x)
	{
		int res=0;
		for(int i=x;i>0;i-=lowbit(i)) res+=t[i];
		return res;
	}
}ch;
void Init()
{
	for(int i=1;i<=n;i++) san[i]=a[i];
	sort(san+1,san+n+1);
	int tot=unique(san+1,san+n+1)-(san+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(san+1,san+tot+1,a[i])-san;
	return;
}
LL check(int va)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]<va) op[i]=-1;
		else op[i]=1;
	}
	op[0]=0;
	for(int i=1;i<=n;i++) op[i]=op[i-1]+op[i];
	LL cnt=0;
	for(int i=n;i>=0;i--)
	{
		cnt+=(ch.ca(2*(n+1))-ch.ca(n+1+op[i]-1));
		ch.add(op[i]+n+1,1);
	}
	for(int i=0;i<=n;i++) ch.add(op[i]+n+1,-1);
	return cnt;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	Init();
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	int l=1,r=n,best=-1;
	LL all=1ll*n*(n-1)/2+n;
	LL pos=all/2+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(b[mid])>all-pos) best=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",san[b[best]]);
	return 0;
}