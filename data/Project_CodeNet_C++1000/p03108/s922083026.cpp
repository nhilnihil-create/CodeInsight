#include <iostream>
#include <vector>

using namespace std;
struct UnionFind {
	vector<long long> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(long long N) : par(N) { //最初は全てが根であるとして初期化
		for (long long i = 0; i < N; i++) par[i] = -1;
	}

	long long root(long long x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] < 0) return x;
		return par[x] = root(par[x]);
	}

	void unite(long long x, long long y) { // xとyの木を併合
		long long rx = root(x); //xの根をrx
		long long ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[ry] += par[rx];
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}
	bool same(long long x, long long y) {
		long long rx = root(x);
		long long ry = root(y);
		return rx == ry;
	}
	long long size(long long x) {
		return -par[root(x)];
	}
};

int main() {
	long long N, M;
	cin >> N >> M;
	vector<pair<long long, long long>> E(M);
	for (long long i = 0; i < M; i++) cin >> E[i].first >> E[i].second;
	vector<long long> Ans(M);
	UnionFind Nums(N);
	Ans[M - 1] = N * (N - 1) / 2;
	for (long long i = M - 1; i >= 1; i--) {
		long long a = E[i].first, b = E[i].second;
		Ans[i - 1] = Ans[i];
		if (!Nums.same(a - 1, b - 1)) {
			Ans[i - 1] -= Nums.size(a - 1) * Nums.size(b - 1);
			Nums.unite(a - 1, b - 1);
		}
	}
	for (long long a : Ans) cout << a << endl;
}