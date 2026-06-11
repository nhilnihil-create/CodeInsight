#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(4e5)+10;
int n,m,cnt,idx;
vector<int> g[maxn];
char s[maxn];
int dfn[maxn],low[maxn],fa[maxn];
bool inStack[maxn];
stack<int> st;
void tarjan(int u) {
	dfn[u]=low[u]=++idx;
	inStack[u]=1;
	st.push(u);
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (dfn[v]==-1) {
			fa[v]=u;
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (inStack[v])
			low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]) {
		cnt++;
		while (1) {
			int v=st.top();
			st.pop(); inStack[v]=0;
			if (v==u) break;
		}
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	scanf("%s",s+1);
	for (int i=1;i<=m;i++) {
		int x,y; read(x); read(y);
		if (s[x]==s[y]) g[x].push_back(y+n),g[y].push_back(x+n);
		else g[x+n].push_back(y),g[y+n].push_back(x);
	}
	n*=2;
	memset(dfn,-1,sizeof(dfn));
	for (int i=1;i<=n;i++)
		if (dfn[i]==-1) tarjan(i);
	if (cnt==n) printf("No\n");
	else printf("Yes\n");
	return 0;
}