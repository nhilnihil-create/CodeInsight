//daddy's back in town, back to rolling the damn hash yoooo babeeeeees//
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define x first
#define y second
#define pi pair <int, int>
#define vi vector <int>
#define L nod<<1
#define R ((nod<<1)|1)
#define int ll
const ll mod = 998244353;
int n, m, d[100010];
bool viz[100010];
vector<pi> g[100010];

bool dfs(int nod){
	viz[nod]=1;
	for(pi i: g[nod]){
		if(viz[i.x]==0){
			d[i.x]=d[nod]+i.y;
			if(dfs(i.x)==0) return 0;
		}
		else{
			if(d[nod]+i.y!=d[i.x]) return 0;
		}
	}
	return 1;
}

int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int l, r, x;
		cin>>l>>r>>x;
		g[l].pb({r, x});
		g[r].pb({l, -x});
	}
	for(int i=1; i<=n; i++){
		if(viz[i]==0 && dfs(i)==0) return cout<<"No", 0;
	}
	cout<<"Yes";
}