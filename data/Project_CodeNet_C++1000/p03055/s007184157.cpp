#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAXN 200010 
using namespace std;
vector<int> E[MAXN];
int n,maxlen=-1,v;
void dfs(int u,int fa,int dep){
	if(dep>maxlen){
		maxlen=dep;
		v=u;
	}
	for(int i=0;i<E[u].size();i++){
		int to=E[u][i];
		if(to!=fa) dfs(to,u,dep+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v; scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	} 
	dfs(1,0,1);
	maxlen=-1;
	dfs(v,0,1);
	if(maxlen==0) puts("Second");
	else if(maxlen==1) puts("First");
	else if(maxlen==2) puts("Second");
	else puts(maxlen%3==2?"Second":"First");
	return 0;
}