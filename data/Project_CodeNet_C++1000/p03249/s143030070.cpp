#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int t[101010];
long long d[101010];
int siz[101010],fa[101010];
bool cmp(const int &x,const int &y)
{
	return d[x]<d[y];
}
map<long long,int> mp;
int main()
{
	int n;
	scanf("%d",&n);
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		siz[i]=1;
		mp[d[i]]=i;
		t[i]=i;
	}
	sort(t+1,t+n+1,cmp);
	for(int i=n;i>1;i--)
	{
		fa[t[i]]=mp[d[t[i]]+2*siz[t[i]]-n];
		if(fa[t[i]]==0)
		{
			printf("-1");
			return 0;
		}
		siz[fa[t[i]]]+=siz[t[i]];
	}
	for(int i=2;i<=n;i++)
		d[t[1]]-=siz[t[i]];
	if(d[t[1]]!=0)
	{
		printf("-1");
		return 0;
	}
	for(int i=2;i<=n;i++)
		printf("%d %d\n",fa[t[i]],t[i]);
	return 0;
}