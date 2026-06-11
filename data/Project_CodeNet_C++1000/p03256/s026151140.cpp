#include<bits/stdc++.h>
using namespace std;
const int N=800005,M=998244353;
int n,m,u,v,i,head[N],Next[N*2],adj[N*2],d[N],q[N],l,r,k;
char c[200005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	++d[v];
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",c+1);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		if(c[u]=='A'&&c[v]=='A')
			Push(u,v+n);
		if(c[u]=='A'&&c[v]=='B')
			Push(u+n,v+2*n);
		if(c[u]=='B'&&c[v]=='B')
			Push(u+2*n,v+3*n);
		if(c[u]=='B'&&c[v]=='A')
			Push(u+3*n,v);
		swap(u,v);
		if(c[u]=='A'&&c[v]=='A')
			Push(u,v+n);
		if(c[u]=='A'&&c[v]=='B')
			Push(u+n,v+2*n);
		if(c[u]=='B'&&c[v]=='B')
			Push(u+2*n,v+3*n);
		if(c[u]=='B'&&c[v]=='A')
			Push(u+3*n,v);
	}
	for(i=1;i<=n*4;++i)
		if(!d[i])
			q[++r]=i;
	l=1;
	while(l<=r)
	{
		for(i=head[q[l]];i!=0;i=Next[i])
		{
			--d[adj[i]];
			if(d[adj[i]]==0)
				q[++r]=adj[i];
		}
		++l;
	}
	puts(r==4*n?"No":"Yes");
}
