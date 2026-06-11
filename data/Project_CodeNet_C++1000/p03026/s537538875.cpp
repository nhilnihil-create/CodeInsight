#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,tot,ans[N];
vector<int> G[N],c;
void dfs(int u,int fa){
	ans[u]=c.back();
	c.pop_back();
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		c.push_back(read());
	}
	sort(c.begin(),c.end());
	for(auto x:c)tot+=x;
	tot-=c.back();
	dfs(1,0);
	printf("%d\n",tot);
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}

