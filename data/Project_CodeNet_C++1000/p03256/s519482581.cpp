//Copyright(c)2018 Mstdream
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=400010;
vector<int>g[N];
int du[N],n,m,flag=0,q[N],top;
char s[N];
void topsort(){
	for(int i=1;i<=2*n;i++)for(auto x:g[i])du[x]++;
	for(int i=1;i<=2*n;i++)if(!du[i])q[++top]=i;
	while(top){
		int v=q[top--];
		for(auto x:g[v]){
			du[x]--;
			if(!du[x])q[++top]=x;
		}
	}
	for(int i=1;i<=2*n;i++)if(du[i])flag=1;
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(s[u]==s[v])g[u+n].push_back(v),g[v+n].push_back(u);
		else g[u].push_back(v+n),g[v].push_back(u+n);
	}
	topsort();
	puts(flag?"Yes":"No");
}
