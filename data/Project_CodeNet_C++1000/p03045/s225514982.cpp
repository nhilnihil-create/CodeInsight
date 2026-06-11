#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u,v;
}e[100001];

int fa[100001];

int findfa(int x)
{
	if(x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		fa[i]=i;
	
	int f1,f2,temp;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>temp;
		f1=findfa(e[i].u);
		f2=findfa(e[i].v);
		if(f1!=f2) fa[f1]=f2;
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++)
    	if(fa[i]==i) cnt++;
    
	cout<<cnt<<endl;
	return 0;
}