#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

class UnionFind {
	vector<int>par, sz;
public:
	UnionFind() {}
	UnionFind(int n) {
		par = sz = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)return;
		if (sz[x] > sz[y]) {
			par[y] = x;
			sz[x] += sz[y];
		}
		else {
			par[x] = y;
			sz[y] += sz[x];
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return sz[find(x)];
	}
};

int main() {
  ll N,M;
  cin >> N >> M;
  int A[M],B[M];
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
  }
  UnionFind uf(N);
  ll ans[M+1];
  ans[M] = (N * (N-1))/2LL;
  for (int i = M-1; i >= 0; i--) {
    if (uf.same(A[i],B[i])) {
      ans[i] = ans[i+1];
    } else {
      ans[i] = ans[i+1] - ((ll)uf.size(A[i]) * (ll)uf.size(B[i]));
      uf.unite(A[i],B[i]);
    }
  }
  for (int i = 0; i < M; i++) {
    cout << ans[i+1] << endl;
  }
  return 0;
}