#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char c[N]; int head[N],vis[N],del[N],tot,d[N][2];
struct Edge{int v,next;Edge(int _v=0,int _n=0):v(_v),next(_n){}}edge[N];
inline void add(int x,int y){edge[++tot]=Edge(y,head[x]);head[x]=tot;}
void dfs(int x)
{	vis[x]=1;
	for(rint i=head[x];i;i=edge[i].next)
	if(!del[to])
	{	if(!vis[to]) dfs(to);
		else printf("Yes"),exit(0);
	}
}
int main()
{	int n,m,x,y; cin>>n>>m; scanf("%s",c+1);
	for(rint i=1;i<=m;i++)
	scanf("%d%d",&x,&y),d[x][c[y]-'A']++,d[y][c[x]-'A']++,add(x,y),add(y,x);
	queue<int> q;
	for(rint i=1;i<=n;i++) if(!d[i][0]||!d[i][1]) del[i]=1,q.push(i);
	while(!q.empty())
	{	int x=q.front(); q.pop();
		for(rint i=head[x];i;i=edge[i].next)
		if(!del[to])
		{	d[to][c[x]-'A']--;
			if(!d[to][0]||!d[to][1]) del[to]=1,q.push(to);
		}
	}
	for(rint i=1;i<=n;i++)// if(!del[i]) printf("Yes");
	if(!del[i]&&!vis[i]) dfs(i);
	printf("No");
	return 0;
}
