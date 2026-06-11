#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
const int mxn=1e5+5;
ll sz[mxn];
vi adj[mxn];
ll dis[mxn];

void dfs(int u, int p=-1){
	for(auto v:adj[u]){
		if(v==p)continue;
		dis[v]=dis[u]+1LL;
		dfs(v,u);
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	pll dist[n];
	map<ll,int>vis;
	map<ii,bool>ans;
	for(int i=0; i<n; i++){
		cin >> dist[i].fi;
		dist[i].se=(ll)i;
		sz[i]=1LL;
		vis[dist[i].fi]=i;
	}
	sort(dist,dist+n);
	for(int i=n-1; i>0; i--){
		auto ind = dist[i].se;
		auto next = dist[i].fi-n+2*sz[ind];
		if(vis.find(next)==vis.end()||next>=dist[i].fi){
			cout << -1 << endl;
			return 0;
		}
		auto ptr = vis[next];
		if(ptr==ind){
			cout << -1 << endl;
			return 0;
		}
		sz[ptr] += sz[ind];
		adj[ind].eb(ptr);
		adj[ptr].eb(ind);
		ans[ii(ptr,ind)]=1;
	}
	bool ok=0;
	for(int i=0; i<n&&!ok; i++){
		if(sz[i]==n)ok=1;
	}
	dfs(dist[0].se);
	ll sum=0;
	for(int i=0; i<n; i++)sum += dis[i];
	if(sum!=dist[0].fi)ok=0;
	if(!ok)cout << -1 << endl;
	else{
		for(auto x:ans){
			cout << x.fi.fi+1 << ' ' << x.fi.se+1 << endl;
		}	
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
