#include <iostream>
#include <vector>
#include <set>
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
	vector<int>A(M);
	vector<int>B(M);
	for (int n = 0; n < M; ++n) {
		cin >> A[n] >> B[n];
		--A[n];
		--B[n];
	}
	int count = 0;
	{
		UnionFind uf(N);
		for (int n = 0; n < M; ++n) {
			uf.merge(A[n], B[n]);
		}
		set<int>st;
		for (int n = 0; n < N; ++n) {
			st.insert(uf.root(n));
		}
		count = st.size();
	}
	int ans = 0;
	for (int i = 0;i<M;++i) {
		UnionFind uf(N);
		for (int n = 0; n < M; ++n) {
			if (n==i) {
				continue;
			}
			uf.merge(A[n], B[n]);
		}
		set<int>st;
		for (int n = 0; n < N; ++n) {
			st.insert(uf.root(n));
		}
		if (count != st.size()) {
			ans++;
		}
	}
	cout << ans <<endl;
}
