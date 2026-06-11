#include <bits/stdc++.h>
using namespace std;
const int N=200100;
vector<int> g[N];
char s[N];
bool ban[N],ba[N],in[N];
int d[N],fa[N],vis[N],num[N][2];
bool fl=0;
int cnt;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
	if (find(x)!=find(y))
	fa[find(x)]=find(y);
}
bool dfs(int x){
	//cerr<<"dfs"<<x<<" "<<s[x]<<endl;
	vis[x]=1;
	if (ban[x]) return 1;
	bool fl1=0;
	for (size_t j=0; j<g[x].size(); ++j) if (g[x][j]=='A'&&dfs(g[x][j])) fl1=1;
	if (!fl1) return 0;
	for (size_t j=0; j<g[x].size(); ++j) if (g[x][j]=='B'&&dfs(g[x][j])) return 1;
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1; i<=m; ++i){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		++num[x][s[y]=='B'];
		++num[y][s[x]=='B'];
	}
	queue<int> q;
	for (int i=1; i<=n; ++i) if (num[i][0]==0||num[i][1]==0) q.push(i),in[i]=1;
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (auto i:g[x])
			if (!in[i]&&!--num[i][s[x]=='B']){
				q.push(i);
				in[i]=1;
			}
	}
	for (int i=1; i<=n; ++i) if (!in[i]) return puts("Yes"),0;
	puts("No");
}
