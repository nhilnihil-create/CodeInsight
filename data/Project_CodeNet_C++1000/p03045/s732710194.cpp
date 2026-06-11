#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()

const int INF = 1001001001;

struct XYZ{
	int x, y, z;
};

struct UnionFind{
	vector<int> par;
	vector<int> rank;
	UnionFind(int n) : par(n), rank(n){
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if (x == y) return;
		if(rank[x] < rank[y]){
			par[x] = y;
		} else {
			par[y] = x;
			if(rank[x] == rank[y]) rank[x] ++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}	
};

int main(){
	int n, m; cin >> n >> m;
	vector<bool> num(n, false);
	vector<XYZ> h(m);
	UnionFind uf(2*n);
	rep(i, m){
		int x, y, z; cin >> x >> y >> z;
		-- x; -- y;
		uf.unite(x,y);
		// if(z%2){
		// 	uf.unite(x+n, y+n);
		// 	uf.unite(x, y);	
		// }else{
		// 	uf.unite(x+n, y);
		// 	uf.unite(x, y+n);
		// }
		
	}
	map<int,int> mp;
	rep(i, n){
		mp[uf.find(i)] += 1;
	}
	int cnt = 0;
	for (auto x : mp){
		cnt ++;
	} 
	cout << cnt << endl;
}