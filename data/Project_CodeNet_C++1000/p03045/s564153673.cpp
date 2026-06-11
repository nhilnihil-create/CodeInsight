#include "bits/stdc++.h"
using namespace std;

struct UnionFind {
	vector<int> par;

	UnionFind(int n) : par(n, -1) { }
	void init(int n) { par.assign(n, -1); }

	int root(int x) {
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y); // merge technique
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[root(x)];
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<int>X(M); 
	vector<int>Y(M); 
	vector<int>Z(M);
	for (int n = 0;n<M; ++n) {
		cin >> X[n] >> Y[n] >> Z[n];
		--X[n];
		--Y[n];
	}
	UnionFind uf(N);
	for (int n = 0; n < M; ++n) {
		uf.merge(X[n],Y[n]);
	}	
	set<int>st;
	for (int n = 0; n < N; ++n) {
		st.insert(uf.root(n));
	}
	cout << st.size()<<endl;
	return 0;
}
