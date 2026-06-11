#include<bits/stdc++.h>
using namespace std;
#define re register
long long d[1001000];
int p[1001000],pq[1001000],fa[1001000],sz[1001000],n;
inline bool cmp(re int A,re int B){return d[A]<d[B];}
inline bool cmp1(re int A,re int B){return d[A]-n+2*sz[A]<d[B]-n+2*sz[B];}
int main()
{
	re int ta=1;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%lld",&d[i]),p[i]=i,sz[i]=1;
	sort(p+1,p+n+1,cmp);
	pq[1]=p[n];
	for(re int i=n-1;i;i--)
	{
		while(ta&&d[p[i]]==d[pq[1]]-n+2*sz[pq[1]])
		{
			fa[pq[1]]=p[i];sz[p[i]]+=sz[pq[1]];
			pop_heap(pq+1,pq+ta+1,cmp1);
			ta--;
		}
		pq[++ta]=p[i];
		push_heap(pq+1,pq+ta+1,cmp1);
	}
	if(ta!=1)puts("-1");
	else
	{
		re long long ans=0;
		for(re int i=1;i<=n;i++)if(fa[i])ans+=sz[i];else ans-=d[i];
		if(ans==0){for(re int i=1;i<=n;i++)if(fa[i])printf("%d %d\n",i,fa[i]);}
		else puts("-1");
	}
}