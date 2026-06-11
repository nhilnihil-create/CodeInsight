#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ld long double

using edge = pair<int, int>;

struct UnionFind{
    vector<int> data;
    /* constructor */
    UnionFind(int sz){ data.assign(sz,-1); }
    /* merge the set to which x belongs and the set to which y belongs */
    bool unite(int x,int y){
        x = find(x); y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    /* find the root of k */
    int find(int k){
        if (data[k] < 0) return k;
        return data[k] = find(data[k]);
    }
    /* calculate the size of the set to which k belongs */
    int size(int k){ return -data[find(k)]; }
};

bool is_bridge(int id, int n, vector<edge>& e){
	UnionFind uf(n);
	for (int i = 0; i < e.size(); ++i){
		if (i != id){
			int p = e[i].first, q = e[i].second;
			uf.unite(p, q);
		}
	}
	int n1 = e[id].first, n2 = e[id].second;
	return uf.find(n1) != uf.find(n2);
}

int main(void){
	int N, M; cin >> N >> M;
	vector<edge> e(M);
	for (int i = 0; i < M; ++i){
		int a, b; cin >> a >> b;
		--a, --b;
		e[i] = {a, b};
	}
	int res = 0;
	for (int i = 0; i < M; ++i)
		res += is_bridge(i, N, e);
	cout << res << endl;
	return 0;
}