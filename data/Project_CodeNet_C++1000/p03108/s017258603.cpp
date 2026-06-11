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
	long long N, M;
	cin >> N >> M;
	vector<int>A(M);
	vector<int>B(M);
	vector<long long>Ans(M + 1);
	for (int n = 0; n < M; ++n) {
		cin >> A[n] >> B[n];
		--A[n];
		--B[n];
	}
	UnionFind uf(N);
	Ans[M] = (N - 1)*N / 2;
	for (int n = 0; n < M; ++n) {
		Ans[M - 1 - n] = Ans[M - n];
		if (!uf.issame(A[M - 1 - n],B[M - 1 - n])) {
			long long x = uf.size(A[M - 1 - n]);
			long long y = uf.size(B[M - 1 - n]);
			Ans[M - 1 - n] += (x * x + y * y - (x + y)*(x + y)) / 2;
			//Ans[M - 1 - n] -= x* y;
		}
		uf.merge(A[M - 1 - n], B[M - 1 - n]);
	}
	
	for (int n = 0; n < M; ++n) {
		cout << Ans[n+1] << endl;
	}
	return 0;
}
