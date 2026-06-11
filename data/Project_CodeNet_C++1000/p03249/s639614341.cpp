#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;

int n;
P d[200000];
vector<int>E[200000];
int sz[200000];
ll dp1[200000];
vector<pair<int,int>>ans;

void dfs1(int v){
	for(int u:E[v]){
		dfs1(u);
		ans.push_back({v+1,u+1});
		dp1[v]+=dp1[u]+sz[u];
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
	if(dp1[d[0].second]!=d[0].first){
		puts("-1");return 0;
	}
	for(auto p:ans){
		printf("%d %d\n",p.first,p.second);
	}
}