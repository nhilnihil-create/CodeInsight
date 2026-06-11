#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,size[100005],sa[100005],pa[100005];
ll d[100005];
bool cmp(int a,int b)
{
	return d[a]>d[b];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		int x=sa[i];
		size[x]++;
		ll a=d[x]-n+2*size[x];
		int l=i+1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(d[sa[mid]]<a)r=mid-1;
			else l=mid+1;
		}
		if(d[sa[r]]!=a)
		{
			printf("-1\n");
			return 0;
		}
		pa[x]=sa[r];
		size[sa[r]]+=size[x];
	}
	ll sum=0;
	for(int i=1;i<n;i++)sum+=size[sa[i]];
	if(sum!=d[sa[n]])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	  if(pa[i])printf("%d %d\n",i,pa[i]);
	return 0;
}