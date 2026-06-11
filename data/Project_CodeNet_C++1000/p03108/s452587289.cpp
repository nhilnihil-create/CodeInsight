#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

struct UnionFind
{
	int N;
	vector<int> parent;
	vector<int> size_r;
	int num_of_sets;

	UnionFind(int N) :  N(N), parent(N), size_r(N, 1), num_of_sets(N) {
		for (int i = 0; i < N; ++i) parent[i] = i;
	}

	int root(int x) {
		if (parent[x] == x) return x;
		return parent[x] = root(parent[x]);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (size_r[x] < size_r[y]) swap(x, y);
		parent[y] = x;
		size_r[x] += size_r[y];
		size_r[y] = 0;
		num_of_sets--;
		return true;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return size_r[root(x)];
	}

	vector<int> roots() {
		vector<int> v(N);
		for (int i = 0; i < N; ++i) v[i] = root(i);
		return v;
	}
};

int main() {
	long long n, m;
	cin >> n >> m;
	int A[m], B[m];
	for (int i = 0; i < m; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}
	UnionFind U(n);
	vector<long long> ans;
	long long x = 0;
	for (int i = m-1; i >= 0; i--) {
		ans.push_back(x);
		int a = A[i], b = B[i];
		if (U.same(a, b)) continue;
		x += (long long)U.size(a) * U.size(b);
		U.merge(a, b);
	}
	for (int i = m-1; i >= 0; i--) {
		cout << x - ans[i] << endl;
	}
	return 0;
}