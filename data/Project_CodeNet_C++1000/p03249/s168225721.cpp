#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,head[100001],tot;
struct node
{
	int sum,id,size,fa;
}a[100001];
struct sb
{
	int to,nextn;
}con[100001];
inline void ADD(int from,int to)
{
	con[++tot].to=to,con[tot].nextn=head[from];
	head[from]=tot;
}
inline int cmp(node x,node y)
{
	return x.sum>y.sum;
}
inline int find(int V)
{
	int l=1,r=n,bck=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].sum>=V)
			bck=mid,l=mid+1;
		else
			r=mid-1;
	}
	return bck;
}
inline int check(int u,int fa)
{
	int bck=0;
	for(register int i=head[u];i!=0;i=con[i].nextn)
	{
		int v=con[i].to;
		if(v==fa)
			continue;
		bck+=check(v,u);
	}
	return bck+a[u].size-1;
}
signed main()
{
	n=read();
	for(register int i=1;i<=n;++i)
	{
		a[i].id=i;
		a[i].sum=read();
		a[i].size=1;
	}
	sort(a+1,a+n+1,cmp);
	a[0].sum=0x7f7f7f7f7f7f7f7f;
	for(register int i=1;i<n;++i)
	{
		int sum=a[i].sum+a[i].size-(n-a[i].size);
		if(sum>=a[i].sum)
		{
			puts("-1");
			return 0;
		}
		int zone=find(sum);
		if(a[zone].sum!=sum)
		{
			puts("-1");
			return 0;
		}
		a[zone].size+=a[i].size;
		a[i].fa=zone;
		ADD(zone,i);
	}
	if(check(n,0)!=a[n].sum)
	{
		puts("-1");
		return 0;
	}
	for(register int i=1;i<n;++i)
		printf("%lld %lld\n",a[i].id,a[a[i].fa].id);
	return 0;
}