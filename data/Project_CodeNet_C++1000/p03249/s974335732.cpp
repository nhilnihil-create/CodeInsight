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
ll sz[mxn],dis[mxn];
vi adj[mxn];
bool vis[mxn];

void dfs(int u, int p=-1){
	for(int v:adj[u])
		if(v!=p)dis[v]=dis[u]+1LL,dfs(v,u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	pair<ll,int> dist[n];
	map<ll,int>mp;
	for(int i=0; i<n; i++){
		cin >> dist[i].fi;
		dist[i].se=i;
		sz[i]=1LL;
		mp[dist[i].fi]=i;
	}
	map<ii,bool>edge;
	sort(dist,dist+n);
	for(int i=n-1; i>0; i--){
		int ind = dist[i].se;
		ll next = dist[i].fi-n+2*sz[ind];
		if(mp.find(next)==mp.end()){
			cout << -1 << endl;
			return 0;
		}
		int ptr = mp[next];
		if(ptr==ind){
			cout << -1 << endl;
			return 0;
		}
		sz[ptr] += sz[ind];
		if(ptr>ind)swap(ind,ptr);
		edge[ii(ptr,ind)]=1;
		adj[ind].eb(ptr);
		adj[ptr].eb(ind);
		vis[ind]=1; vis[ptr]=1;
	}
	bool ok=0;
	for(int i=0; i<n&&!ok; i++)
		if(sz[i]==n)ok=1;
	for(int i=0; i<n; i++)
		if(!vis[i])ok=0;
	dfs(dist[0].se);
	ll sum = 0;
	for(int i=0; i<n; i++)sum+=dis[i];
	if(sum!=dist[0].fi)ok=0;
	if(!ok)cout << -1 << endl;
	else{
		for(auto x:edge)
			cout << x.fi.fi+1 << ' ' << x.fi.se+1 << endl;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
