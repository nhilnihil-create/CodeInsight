#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct Val{
	long long d;
	int u;
}p[100010];
bool cmp(Val a,Val b)
{
	return a.d>b.d;
}
int find(int l,int r,long long t)
{
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(p[mid].d<=t)r=mid;
		else l=mid;
	}
	if(p[r].d!=t)return -1;
	return r;
}
int u[100010],v[100010];
int siz[100010];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].d);
		p[i].u=i;
	}
	sort(p+1,p+n+1,cmp);
	long long res=0;
	for(int i=1;i<n;i++)
	{
		siz[i]++;
		u[i]=p[i].u;
		int pos=find(i,n,p[i].d+siz[i]-(n-siz[i]));
		if(pos==-1){
			printf("-1\n");
			return 0;
		}
		v[i]=p[pos].u;
		siz[pos]+=siz[i];
		res+=siz[i];
	}
	if(res!=p[n].d){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<n;i++)
		printf("%d %d\n",u[i],v[i]);
	return 0;
}