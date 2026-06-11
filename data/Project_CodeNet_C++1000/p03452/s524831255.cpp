#include<bits/stdc++.h>
using namespace std;
int fa[100005],k[100005];
int f(int u)
{
	if(u==fa[u])
		return u;
	else
	{
		int t=f(fa[u]);
		k[u]+=k[fa[u]];
		return fa[u]=t;
	}
}
int main()
{
	int i,l,r,d,p,q,n,m;
	cin>>n>>m; 
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
		k[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		cin>>l>>r>>d;
		if(f(l)==f(r))
		{
			if(k[r]-k[l]!=d)
			{
				puts("No");
				return 0;
			}
		}
		else
		{
			p=f(r),q=f(l);
			fa[p]=q;
			k[p]=k[l]-k[r]+d;
		}
	}
	puts("Yes");
	return 0;
}