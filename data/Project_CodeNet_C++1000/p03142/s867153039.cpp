#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dfs(int v, vector<int> &memo, vector<vector<int>> &G, vector<int> &order){
	memo[v] = 1;
	for(auto nv : G[v]){
		if(memo[nv] == 2) continue;
		if(memo[nv] == 1) return false;
		if(!dfs(nv, memo, G, order)) return false;
	}
	memo[v] = 2;
	order.push_back(v);
	return true;
}

bool tsort(vector<vector<int>> &G, vector<int> &order){
	vector<int> memo(G.size(), 0);
	rep(i,G.size()){
		if(memo[i] != 0) continue;
		if(!dfs(i, memo, G, order)) return false;
	}
	reverse(order.begin(), order.end());
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n), RG(n);
	rep(i,n+m-1){
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		RG[b].push_back(a);
	}
	vector<int> order;
	tsort(G, order);
	
	map<int, int> zip;
	rep(i,order.size()) zip[order[i]] = i;

	int root = order[0];
	vector<int> par(n, -1);
	par[root] = 0;
	for(int i = 1; i < order.size(); ++i){
		int p = -1, hoge = -1;
		for(int nex : RG[order[i]]){
			if(par[nex] == -1) continue;
			if(hoge < zip[nex]){
				hoge = zip[nex];
				p = nex;
			}
		}
		par[order[i]] = p + 1;
	}

	rep(i,n) cout << par[i] << endl;
	return 0;
}