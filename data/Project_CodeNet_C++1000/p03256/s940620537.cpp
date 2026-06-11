#include<cstdio>
int n,m,d[200050],p[200050][2],head[200050],q[200050],t,num=1,vis[200050];
struct r{
	int to,last;
}e[400050];
void add(int u,int v){
	e[num].to=v;e[num].last=head[u];head[u]=num++;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int c=getchar();
		while (c<'A'||c>'B')c=getchar();
		d[i]=c-'A';
	}
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		p[u][d[v]]++;p[v][d[u]]++;
		add(u,v);add(v,u);
	}
	for (int i=1;i<=n;i++)if (!p[i][0]||!p[i][1])q[++t]=i,vis[i]=1;
	for (int h=1;h<=t;h++){
		int x=q[h];
		for (int i=head[x];i;i=e[i].last)if (!vis[e[i].to]){	
			p[e[i].to][d[x]]--;
			if (!p[e[i].to][d[x]])q[++t]=e[i].to,vis[e[i].to]=1;
		}
	}
	if (t<n)printf("Yes");
	else printf("No");
}