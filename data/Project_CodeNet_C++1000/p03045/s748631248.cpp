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

int main()
{
	int N, M;
	cin >> N >> M;
	UnionFind uf(N);
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		X--; Y--;
		uf.merge(X, Y);
	}
	set<int> st;
	for (int i = 0; i < N; i++) {
		st.insert(uf.root(i));
	}
	cout << st.size() << endl;
}
