#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;

int n;
P d[200000];
vector<int>E[200000];
int sz[200000];
ll dp1[200000],dp2[200000];
vector<pair<int,int>>ans;

void dfs1(int v){
	for(int u:E[v]){
		dfs1(u);
		dp1[v]+=dp1[u]+sz[u];
	}
}
void dfs2(int v,int p){
	if(p==-1)dp2[v]=dp1[v];
	else dp2[v]=dp2[p]+n-2*sz[v];
	for(int u:E[v]){
		ans.push_back({v+1,u+1});
		dfs2(u,v);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%lld",&d[i].first);
		d[i].second=i;
	}
	rep(i,n)sz[i]=1;
	sort(d,d+n);
	for(int i=n-1;i>0;i--){
		ll c=d[i].first-n+2*sz[d[i].second];
		int id=lower_bound(d,d+n,P(c,0))-d;
		if(id==n||d[id].first!=c){
			puts("-1");return 0;
		}
		E[d[id].second].push_back(d[i].second);
		sz[d[id].second]+=sz[d[i].second];
	}
	dfs1(d[0].second);
	dfs2(d[0].second,-1);
	rep(i,n){
		if(dp2[d[i].second]!=d[i].first){
			puts("-1");return 0;
		}
	}
	for(auto p:ans){
		printf("%d %d\n",p.first,p.second);
	}
}