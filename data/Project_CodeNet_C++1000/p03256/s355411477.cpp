#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=2*(1e5)+10;
struct xxx{
	int y,nxt;
}a[N*2];
char s[N];
queue<int> q;
int h[N],cnt[N][2],in[N];
int n,m,tot,node;
void add(int x,int y){a[++tot].y=y; a[tot].nxt=h[x]; h[x]=tot;}
void prework(){
	int u;
	for (int i=1;i<=n;++i){
		for (int j=h[i];j!=-1;j=a[j].nxt){
			u=a[j].y;
			++cnt[i][s[u]-'A'];
		}
	}
}
bool solve(){
	int u,v;
	while (!q.empty()) q.pop();
	for (int i=1;i<=n;++i)
		if (!cnt[i][0]||!cnt[i][1]) q.push(i),in[i]=1;
	node=0;
	while (!q.empty()){
		v=q.front(); q.pop(); ++node;
		for (int i=h[v];i!=-1;i=a[i].nxt){
			u=a[i].y;
			--cnt[u][s[v]-'A'];
			if (!in[u]&&cnt[u][s[v]-'A']==0) q.push(u),in[u]=1;
		}
	}
	if (node!=n) return true;
	return false;
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	int x,y;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	memset(h,-1,sizeof(h));
	tot=0;
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	prework();
	if (solve()) printf("Yes\n");
	else printf("No\n");
}
