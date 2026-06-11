#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
const int N = 1e5+1;

vector<vector<int>> adj(N);
bitset<N> vu;

pair<int,int> dfs(int node){
	int w = 1, b = 1;
	for (int i:adj[node]){
		if (!vu[i]){
			vu[i] = true;
			auto p = dfs(i);
			w *= (p.first+p.second)%mod;
			w %= mod;
			b *= p.first;
			b %= mod;
		}
	}
	return make_pair(w,b);
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n-1; ++i){
		int a,b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	vu[1] = true;
	auto p = dfs(1);
	cout << (p.first+p.second)%mod;
	return 0;
}
