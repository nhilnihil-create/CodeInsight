#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

struct Unionfind {
	vector< int > par;
	Unionfind(int N) : par(N,-1){
	}
	bool unite(int x, int y) {
		x = root(x), y = root(y);
		if(x == y) return 0;
		if(par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return 1;
	}
	int root(int k) {
		if(par[k] < 0) return (k);
		return (par[k] = root(par[k]));
	}
	bool same(int x, int y){
		x = root(x);
		y = root(y);
		return x==y;
	}
	int size(int k) {
		return (-par[root(k)]);
	}
};

int main(){
	
	int n,m; cin>>n>>m;
	Unionfind uf(n);
	for(int i=0; i<m; i++){
		int x,y,z; cin>>x>>y>>z;
		x--; y--;
		uf.unite(x,y);
	}
	int cnt{};
	for(int i=0; i<n; i++){
		if(uf.root(i)==i) cnt++;
	}
	cout << cnt << endl;
	
}

