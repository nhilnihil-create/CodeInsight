#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=200050;
const int M=2*N;
char col[N];
vector<int> E[M];
int cyc[M];
bool cycle=0;
void DFS(int u)
{
	cyc[u]=1;
	for(int v:E[u])
	{
		if(!cyc[v]) DFS(v);
		else if(cyc[v]==1) cycle=1;
	}
	cyc[u]=2;
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	scanf("%s",col+1);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		if(col[u]==col[v]) E[u].pb(v+n),E[v].pb(u+n);
		else E[u+n].pb(v),E[v+n].pb(u);
	}
	for(i=1;i<=n;i++) if(!cyc[i]) DFS(i);
	if(cycle) printf("Yes\n");
	else printf("No\n");
	return 0;
}