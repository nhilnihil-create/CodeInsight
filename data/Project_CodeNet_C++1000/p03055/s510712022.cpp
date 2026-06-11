//树的直径板子 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,b,n,l,dis[200100],S;
vector <int> G[200100];
void dfs(int u,int f)
{
    dis[u]=dis[f]+1;
    for(int i=0;i<G[u].size();i++)
	{
        if(G[u][i]!=f) dfs(G[u][i],u);
    }
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i < n;i ++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0);
    for(int i=1;i<=n;i++) if(dis[i]>dis[S]) S=i;  
    dfs(S,0);
    for(int i=1;i<=n;i++) l=max(l,dis[i]-1);
    
	if(l % 3 == 1) printf("Second\n"); 
	else	printf("First\n");
    return 0;
}
