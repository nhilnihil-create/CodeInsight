#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) f^=(ch=='-');
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return f ? -x : x;
}
const int maxn=1e5+10;
int n,m,head[maxn],cnt=0,col[maxn],ans,tot1=0,tot2=0;
bool flag=0;
struct node{
	int to,nxt;
}e[maxn<<1];
inline void add(int u,int v) {
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
} 
void dfs(int u,int COL) {
	if (flag) return;
	col[u]=COL;
	if (COL==1) ++tot1;
	else ++tot2;
	for (int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if (!col[v]) dfs(v,3-COL);
		else if (col[v]==COL) {
			flag=1;
			return;
		}
 	}
}
signed main(){
	n=read(); m=read();
	for (int i=1,u,v;i<=m;++i) {	
		u=read(); v=read();
		add(u,v); add(v,u);
	}
	memset(col,0,sizeof(col));
	dfs(1,1);
	if (flag) ans=n*(n-1)/2;
	else ans=tot1*tot2;
	printf("%lld\n",ans-m);
	return 0;
}