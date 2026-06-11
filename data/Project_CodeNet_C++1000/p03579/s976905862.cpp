#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

class unionfind{ // 0-indexed
public:
	vector<int> parent;
	vector<size_t> size;
	size_t num_of_disjointsets;
	unionfind(size_t n){
		parent.resize(n, -1);
		size.resize(n, 1);
		num_of_disjointsets = n;
	}

	size_t find(size_t x){
		if(parent[x] == -1) return x;
		return parent[x] = find(parent[x]);
	}

	size_t unite(size_t x, size_t y){
		x = find(x);
		y = find(y);
		if(x == y) return -1;
		if(size[x] < size[y]){
			parent[x] = y;
			size[y] += size[x];
			size[x] = 0;
			--num_of_disjointsets;
			return y;
		}else{
			parent[y] = x;
			size[x] += size[y];
			size[y] = 0;
			return x;
			--num_of_disjointsets;
		}
	}

	bool united(size_t x, size_t y){
		return find(x) == find(y);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n, m; cin >> n >> m;
	unionfind uf(2*n);
	for(Int i=0; i<m; ++i){
		Int a, b; cin >> a >> b; --a; --b;
		uf.unite(2*a, 2*b+1);
		uf.unite(2*b, 2*a+1);
	}
	bool f = true;
	for(Int i=0; i<n; ++i)
		if(uf.united(2*i, 2*i+1)){
			f = false;
			break;
		}
	if(!f){
		cout << n * (n-1) / 2 - m << "\n";
	}else{
		Int a = 1;
		for(Int i=1; i<n; ++i)
			if(uf.united(0, 2*i))
				++a;
		cerr << a << " " << n-a << "\n";
		cout << a * (n-a) - m << "\n";
	}
}