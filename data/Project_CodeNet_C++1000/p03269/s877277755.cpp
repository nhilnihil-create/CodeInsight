#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int L;
	cin >> L;
	int n, m = 0;
	vector<vector<pair<int, int>>> adj;
	function<void(int)> solve = [&](int x){
		if(x <= 1){
			adj.emplace_back();
			return;
		}
		solve(x / 2);
		int c = int(adj.size());
		adj.emplace_back();
		adj[c - 1].emplace_back(c, 0);
		adj[c - 1].emplace_back(c, x / 2);
		m += 2;
		if(x & 1){
			adj[0].emplace_back(c, x - 1);
			++ m;
		}
	};
	solve(L);
	n = int(adj.size());
	cout << n << " " << m << "\n";
	for(int u = 0; u < n; ++ u){
		for(int i = 0; i < int(adj[u].size()); ++ i){
			int v, w;
			tie(v, w) = adj[u][i];
			cout << u + 1 << " " << v + 1 << " " << w << "\n";
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////