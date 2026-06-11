#include <bits/stdc++.h>
using namespace std;
vector<int>e[200005];char s[200005];
int n,m,sb[200005],sw[200005],x,y,vis[200005],fa[200005],sz[200005],ee[200005];queue<int>q;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	}
	for(int i=1;i<=n;i++) for(int j=0;j<e[i].size();j++) if(s[e[i][j]]=='A') sw[i]++;else sb[i]++;
	for(int i=1;i<=n;i++) if(!sw[i]||!sb[i]) q.push(i),vis[i]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=0;i<e[x].size();i++)
		{
			if(s[x]=='A') sw[e[x][i]]--;
			else sb[e[x][i]]--;
			if(!sw[e[x][i]]||!sb[e[x][i]])
			{
				if(!vis[e[x][i]]) q.push(e[x][i]),vis[e[x][i]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++) if(!vis[i]&&!vis[e[i][j]])
		{
			x=find(i);y=find(e[i][j]);
			if(x==y) ee[x]++;
			else
			{
				sz[x]+=sz[y];
				fa[y]=x;
				ee[x]+=ee[y]+1;
			}
		}
	}
	for(int i=1;i<=n;i++) if(find(i)==i&&ee[i]>=sz[i]) return puts("Yes"),0;
	puts("No");
}