#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int n;
vector<int>d;
vector<pii>ed;
vector<int>G[100010];
map<int,int>mm;
int dp[100010];
int cnt[100010];
bool vis[100010];
int sz[100010];
int ans[100010];
void dfs(int x,int pr=-1LL){
	cnt[x]++;
	vis[x]=1;
	for(auto to:G[x])if(to!=pr){
		if(vis[to])puts("-1"),exit(0LL);
		dfs(to,x);
		dp[x]+=dp[to]+cnt[to];
		cnt[x]+=cnt[to];
	}
}
void dfs2(int x,int pr=-1LL,int w=0LL){
	ans[x]=dp[x]+w;
	w+=dp[x];
	for(auto to:G[x])if(to!=pr)dfs2(to,x,w-dp[to]-cnt[to]+(n-cnt[to]));
}
signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0LL;i<n;i++){
		int x;
		cin>>x;
		d.pb(x);
		mm[x]=i;
	}
	for(auto x=mm.rbegin();x!=mm.rend();x++){
		int node=x->S,val=x->F;
		sz[node]++;
		int op=n-sz[node];
		if(!op)continue;
		int nxt=val+sz[node]-op;
		if(mm.count(nxt)){
			int ne=mm[nxt];
			sz[ne]+=sz[node];
			G[ne].pb(node);
			G[node].pb(ne);
			if(ne>node)swap(ne,node);
			ed.pb(mp(ne+1LL,node+1LL));
		}
	}
	dfs(0LL);
	dfs2(0LL);
	for(int i=0;i<n;i++){
		if(!vis[i])return puts("-1"),0;
		if(ans[i]!=d[i])return puts("-1"),0;
	}
	for(auto x:ed)cout<<x.F<<' '<<x.S<<endl;
	return 0;
}
