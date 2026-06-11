#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

struct Unionfind {
	vector<int> parent;

	Unionfind(int N) {
		parent = vector<int>(N, -1);
	}

	int root(int x) {
		if (parent[x] < 0) return x;
		return parent[x] = root(parent[x]);
	}

	int size(int x) {
		return -parent[root(x)];
	}

	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (size(x) < size(y)) swap(x, y);
		parent[x] += parent[y];
		parent[y] = x;
		return;
	}

};

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	rep(i, M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}
	Unionfind uni(N);
	vector<ll> ans(M);
	ans[M - 1] = (ll)N * (N - 1) / 2;
	for (int i = M - 1; i >= 1; i--) {
		ans[i - 1] = ans[i];
		if (uni.root(A[i]) != uni.root(B[i])) {
			ans[i - 1] -= (ll)uni.size(A[i]) * uni.size(B[i]);
			uni.unite(A[i], B[i]);
		}
	}
	rep(i, M) cout << ans[i] << endl;
}



