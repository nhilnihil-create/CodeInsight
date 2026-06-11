#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//子の数が分かるUnionFind
struct UFT {
private:
	vector<int> par, rank;
	vector<int> c_n; //子の数
	void init(int n = 1) {
		par.resize(n); rank.resize(n); c_n.resize(n);
		for (int i = 0; i < n; i++)par[i] = i, rank[i] = 0, c_n[i] = 1;
	}
	void update(int x) {
		if (par[x] == x)return;
		else {
			int r = root(par[x]);
			c_n[par[x]] += c_n[x];
			par[x] = r;
			return;
		}
	}
	int root(int x) {
		if (par[x] == x)return x;
		else {
			int r = root(par[x]);
			return par[x] = r;
		}
	}
public:
	UFT(int n = 1) {
		init(n);
	}
	int weight(int x) {
		return c_n[root(x)];
	}
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)false;
		if (rank[x] < rank[y])swap(x, y);
		if (rank[x] == rank[y])rank[x]++;
		par[y] = x;
		update(y);
		return true;
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	UFT t(N + 1);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		t.merge(x, y);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (t.issame(p[i], i + 1))ans++;
	}
	cout << ans << endl;
}