#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,m,cnt; 
int d[100005],low[100005],ans;
V<int> v[100005];
void dfs(int p,int lst){
	d[p]=++cnt;
	low[p]=d[p];
	for(auto u:v[p])if(u!=lst){
		if(!d[u]){
			dfs(u,p);
			gmin(low[p],low[u]);
		}else{
			gmin(low[p],d[u]);
		}
	}
	if(low[p]==d[p]&&p!=1){
		ans++;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,1);
	cout<<ans;
	RE 0;
}
