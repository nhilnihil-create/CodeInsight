#include<bits/stdc++.h>
typedef long long lli;
using namespace std;
struct Edge{
	lli nxt,to;
}e[400010];
lli n,m,cnt;
lli col[100010],h[100010];
void add(lli u,lli v)
{
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
void dfs(lli u,lli c)
{
	col[u]=c;
	for(lli i=h[u];i;i=e[i].nxt){
		lli v=e[i].to;
		if(!col[v]) dfs(v,-c);
		if(col[v]==c){
			printf("%lld",n*(n-1)/2-m);
			exit(0);
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(lli a,b,i=1;i<=m;i++){
		scanf("%lld%lld",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,1);
	lli a=0,b=0;
	for(lli i=1;i<=n;i++){
		if(col[i]==1) a++;
		else b++;
	}
	printf("%lld",a*b-m);
}