#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <map>
#include <stack>
#include <cmath>
#define LL long long 
using namespace std; 
 
long long c[100005];

vector <int > v[100005];
int n,m,N;
int anss[100005];

void dfs(int pre,int x)
{
//	cout<<x<<" "<<v[x].size()<<endl;
	anss[x]=c[N--];
	for(int i=0;i<v[x].size();i++)
	{
		if(pre==v[x][i])
			continue;
		dfs(x,v[x][i]);
	}
}

struct Node
{
	int a,b;
}node[100005];

bool cmp(Node x,Node y)
{
	if(x.a==y.a)
		return x.b<y.b;
	return x.a<y.a;
}

int main()
{

	LL ans=0,maxn=0;
	scanf("%d",&n);
	m=n-1;
	int a,b;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&node[i].a,&node[i].b);
	sort(node+1,node+n,cmp);
	for(int i=1;i<=m;i++)	
	{
		v[node[i].a].push_back(node[i].b);
		v[node[i].b].push_back(node[i].a);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		maxn=max(c[i],maxn);
		ans+=c[i];
	}
	sort(c+1,c+n+1);
	N=n;
//	for(int i=1;i<=n;i++)
//		cout<<c[i]<<" ";
//	cout<<endl;
	ans-=maxn;
	cout<<ans<<endl;
	dfs(1,1);
	for(int i=1;i<=n;i++)
		cout<<anss[i]<<" ";
}