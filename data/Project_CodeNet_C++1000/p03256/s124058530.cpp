#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 10;
char label[maxn];
struct edge{
	int v,next;
	edge(int v = 0,int next = 0) : v(v), next(next) {}
} e[maxn * 2];
int hd[maxn] , ek = 1;
inline void adde(int u,int v){
	e[ek] = edge(v,hd[u]);
	hd[u] = ek++;
}
int clock;
bool dfs(int len,char pas,int u){
	++clock;
	if(clock >= 3e7) return 0;
	for(int i = hd[u];i;i = e[i].next){
		int v = e[i].v;
		if(label[v] == pas) continue;
		if(len >= 3e5) return 1;
		if(dfs(len + 1,label[u],v)) return 1;
	}
	return 0;
}
int main(){
	int n,m;
	scanf("%d%d%s",&n,&m,label + 1);
	for(int i = 1;i <= m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v); adde(v,u);
	}
	for(int i = 1;i <= n;i++)if(dfs(1,'$',i)) return !printf("Yes"); 
	return !printf("No");
} 