#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
vector<pair<ll,int>>vec;
int sz[100005];
vector<int>edge[100005];
ll dist[100005];
void dfs(int v,int u,int d){
	dist[v] = d;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,d+1);
	}
}
ll O;
int main(){
	scanf("%d",&n);
	repn(i,n){
		ll a; scanf("%lld",&a) ; vec.pb(mp(-a,i)); if(i == 1) O = a;
	}
	sort(vec.begin(),vec.end());
	
	repn(i,n) sz[i] = 1;
	
	for(int i=0;i<n-1;i++){
		ll a = vec[i].fi;
		int v = vec[i].sc;
		
		ll need = -a - (n-2*sz[v]);
		int aa = POSL(vec,mp(-need,-1));
		if(aa < vec.size() && -vec[aa].fi != need){
			puts("-1"); return 0;
		}
		//cout << v << " " << vec[aa].sc << endl;
		edge[vec[aa].sc].pb(v);
		edge[v].pb(vec[aa].sc);
		sz[vec[aa].sc] += sz[v];
	}
	fill(dist,dist+100005,1e18);
	dfs(1,-1,0);
	
	repn(i,n){
		O -= dist[i];
	}
	
	if(O){
		puts("-1"); return 0;
	}
	
	repn(i,n){
		rep(j,edge[i].size()){
			int to = edge[i][j];
			if(i < to) printf("%d %d\n",i,to);
		}
	}
	return 0;
}