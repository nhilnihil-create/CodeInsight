#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 1e5+10;

int p[maxn],sz[maxn];

ll tot;

int find_set(int x){
	return p[x] == x ? x : p[x] = find_set(p[x]);
}

void union_set(int a,int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b) return;
	if(sz[a] > sz[b]) swap(a,b);
	tot=tot-sz[a]*sz[b];
	p[a] = b;
	sz[b]+=sz[a];
	sz[a] = 0;
}

void init(){
	for(int i=0;i<maxn;++i){
		p[i]=i;
		sz[i]=1;
	}
}

void solve(){
	ll n,m;
	cin >> n >> m;
	init();
	vector<pair<int,int>> g(m);
	vector<ll> ans(m);
	for(int i=0,a,b;i<m;++i){
		cin >> g[i].first >> g[i].second;
	}
	tot = (n*(n-1))/2LL;
	for(int i=m-1;i>=0;--i){
		ans[i] = tot;
		union_set(g[i].first,g[i].second);
	}
	for(int i=0;i<m;++i){
		cout << ans[i] << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}