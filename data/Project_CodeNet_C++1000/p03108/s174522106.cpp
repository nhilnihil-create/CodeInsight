#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

struct UnionFind {
	vector<int> par;
	UnionFind(int x) : par(x, -1) {}
	void init(int x) { par.assign(x, -1); }
	int root(int x) {
		if (par[x] <= -1) return x;
		else return root(par[x]);
	}
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	int size(int x) {
		return -par[root(x)];
	}
};
int A[100010], B[100010];
ll ans[100010];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}
	ans[M - 1] = (ll)N * (N - 1) / 2;
	UnionFind uf(N);
	for (int i = M - 1; i > 0; i--) {
		ans[i - 1] = ans[i];
		if (!uf.issame(A[i], B[i])) ans[i - 1] -= (ll)uf.size(A[i]) * uf.size(B[i]);
		uf.merge(A[i], B[i]);
	}
	for (int i = 0; i < M; i++) {
		cout << ans[i] << endl;
	}
}