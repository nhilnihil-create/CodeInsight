//Copyright(c)2018 Mstdream
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100010;
int siz[N],n,tot,vis[N],dep[N];
map<LL,int>f;
struct Q{
	LL v;int id;
	bool operator<(const Q&x)const{
		return v>x.v;
	}
}q[N];
vector<int>g[N];
vector<pair<int,int> >ans;
bool flag=1;
void dfs(int x){
	tot++;vis[x]=1;
	for(auto v:g[x]){
		if(vis[v])flag=0;
		else dep[v]=dep[x]+1,dfs(v);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&q[i].v);
		f[q[i].v]=i;
		q[i].id=i;
		siz[i]=1;
	}
	sort(q+1,q+n+1);
	for(int i=1;i<n;i++){
		LL d=q[i].v+2*siz[q[i].id]-n;
		int fa=f[d];
		if(!fa)cout<<"-1"<<endl,exit(0);
		siz[fa]+=siz[q[i].id];
		ans.push_back(make_pair(q[i].id,fa));
		g[fa].push_back(q[i].id);
	}
	dfs(q[n].id);
	for(int i=1;i<=n;i++)q[n].v-=dep[i];
	if(tot==n&&flag&&!q[n].v){
		for(auto x:ans){
			printf("%d %d\n",x.first,x.second);
		}
	}
	else puts("-1");
}
