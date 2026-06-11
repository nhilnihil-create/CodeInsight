#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
vector<int> par,sz;
int find(int x){while(x!=par[x])x=par[x]; return x;}
void uni(int a,int b)
{
	a=find(a);b=find(b);
	if(a==b)return;
	if(sz[a]<sz[b])swap(a,b);
	par[b]=a;sz[a]+=sz[b];
}
bool same(int a,int b)
{
	return find(a)==find(b);
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w", stdout);
	#endif
	int n,m;scanf("%lld%lld",&n,&m);
	sz=vector<int>(n+1,1);
	par=vector<int>(n+1);iota(par.begin(),par.end(),0);
	
	vector<int> p(n+1);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);

	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%lld%lld",&u,&v);
		uni(u,v);
	}

	int ct=0;
	for(int i=1;i<=n;i++)
	{
		if(same(i,p[i]))ct++;
	}
	printf("%lld\n",ct );

	

}