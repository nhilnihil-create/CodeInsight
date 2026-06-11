#include <bits/stdc++.h>
using namespace std;
struct union_find{
	static const int DEFAULT = 200200;
	vector<int> parent;
	int N;
	union_find(int N = DEFAULT) : N(N) {
		clear();
	}
	void clear(){
		parent.assign(N, -1);
	}
	int find(int u){
		return (parent[u] < 0) ? u : parent[u] = find(parent[u]);
	}
	bool is_connected(int u, int v){
		return find(u) == find(v);
	}
	bool join(int u, int v){
		u = find(u);
		v = find(v);
		if (u != v){
			if (parent[u] > parent[v])
				swap(u, v);
			parent[u] += parent[v];
			parent[v] = u;
		}
		return u != v;
	}
	int size(int u){
		return -parent[find(u)];
	}
};
const int maxn = 200200;
vector<int> to[maxn];
long long cost[maxn], sz[maxn];
void dfs(int u, int p){
	sz[u] = 1;
	for(int v : to[u]){
		if(v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		cost[u] += cost[v] + sz[v];
	}
}
int n;
void fix(int u, int p){
	if(p != -1){
		cost[u] = cost[p] + n - 2 * sz[u];
	}
	for(int v : to[u]){
		if(v == p) continue;
		fix(v, u);
	}
}
int main(){
	cin >> n;
	vector<pair<long long, int> > vals;
	map<long long, int> rev;
	union_find uf(n);
	long long sum = 0;
	for(int i = 0; i < n; i++){
		long long x; cin >> x;
		rev[x] = i;
		vals.push_back({x, i});
		sum += x;
	}
	if(sum&1){
		cout << -1 << endl;
		return 0;
	}
	vector<pair<int,int> > edges;
	sort(vals.rbegin(), vals.rend());
	for(int i = 0; i < n - 1; i++){
		long long cost; int u;
		tie(cost, u) = vals[i];
		int sz = uf.size(u);
		long long ncost = cost - n + 2 * sz;
		auto it = rev.find(ncost); 
		if(it == rev.end()){
			cout << -1 << endl;
			return 0;
		}
		int x = u, y = it->second;
		if(x == y){
			cout << -1 << endl;
			return 0;
		}
		if(x > y) swap(x, y);
		if(!uf.join(x, y)){
			cout << -1 << endl;
			return 0;
		}
		edges.push_back({x, y});
		to[x].push_back(y);
		to[y].push_back(x);
	}
	dfs(0, -1);
	fix(0, -1);
	vector<pair<long long, int> > nvals;
	for(int i = 0; i < n; i++) nvals.push_back({cost[i], i});
	sort(nvals.rbegin(), nvals.rend());
	if(nvals != vals){
		cout << -1 << endl;
		return 0;
	}
	sort(edges.begin(), edges.end());
	for(auto e : edges) cout << e.first + 1 << " " << e.second + 1 << endl;
	return 0;
}
