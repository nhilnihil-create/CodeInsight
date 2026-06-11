#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q,u,v,w,ans=0;
int father[200005],visited[200005];

int find(int x)
{
	if (x!=father[x])  father[x]=find(father[x]);
	return father[x];
}

signed main()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++)  father[i]=i;
	for (int i=1;i<=q;i++)
	{
		cin>>u>>v>>w;
		father[find(v)]=find(u);
	}
	for (int i=1;i<=n;i++)  father[i]=find(i);
	for (int i=1;i<=n;i++)  visited[father[i]]++;
	for (int i=1;i<=n;i++)
	{
		if (visited[i])  ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}