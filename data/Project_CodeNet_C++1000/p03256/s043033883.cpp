#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define  LL long long
const int N = 2e5+33;
vector<int>G[N];
char k[N];
int d[N][2];
queue<int>q;
int vis[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",k+1);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		d[u][k[v]-'A']++;
		d[v][k[u]-'A']++;
	}
	for(int i=1;i<=n;i++) if(d[i][0]==0||d[i][1]==0) q.push(i),vis[i]=1;
	int cnt=(int)q.size();
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i];
			if(--d[v][k[u]-'A']==0&&vis[v]==0){
				q.push(v);
				cnt++;
				vis[v]=1;
			}
		}
	}
	if(cnt!=n){
		puts("Yes");
	}else{
		puts("No");
	}


	
	return 0;
}
