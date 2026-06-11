#include <bits/stdc++.h>
using namespace std;
#define N 200100
int n,m,he[N],ne[N<<1],e[N<<1],cnt,fa[N],op[N],C[N][2],Q[N];
char s[N];
void add(int u,int v){ne[++cnt]=he[u];he[u]=cnt;e[cnt]=v;}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
		C[u][s[v]-'A']++; C[v][s[u]-'A']++;
	}
	int h=0,t=0;
	for (int i=1;i<=n;i++) if (!C[i][0] || !C[i][1]) Q[++t]=i;
	while (h!=t){
		int x=Q[++h];
		for (int i=he[x];i;i=ne[i]) {
			C[e[i]][s[x]-'A']--;
			if (!C[e[i]][s[x]-'A'] && C[e[i]][(s[x]-'A')^1]) Q[++t]=e[i];
		}
	}
	if (t==n) puts("No"); else puts("Yes");
	return 0;
}
