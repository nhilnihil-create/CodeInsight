#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int N=2e5+5;
int n,m,x,y,rd[N][2],cnt,head[N],vis[N],num; char s[N];
struct edge{int to,nxt;}e[N<<1];
void adde(int x,int y){e[++cnt].to=y; e[cnt].nxt=head[x]; head[x]=cnt;}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	while (m--) scanf("%d%d",&x,&y),adde(x,y),adde(y,x),rd[x][s[y]-'A']++,rd[y][s[x]-'A']++;
	queue<int> q;
	rep (i,1,n) if (!rd[i][0]||!rd[i][1]) q.push(i),vis[i]=1;//只有连向B的边/A 
	while (!q.empty()){
		int u=q.front(); q.pop(); num++;
		for (int i=head[u],v;i;i=e[i].nxt){
			v=e[i].to;
			if (!--rd[v][s[u]-'A']&&!vis[v]) vis[v]=1,q.push(v);
		}
	}
	puts(num!=n?"Yes":"No");
	return 0;
}
//找形如AABB的环 
//用类似拓扑排序的方法做，对某个点记录A/B连向它的度 