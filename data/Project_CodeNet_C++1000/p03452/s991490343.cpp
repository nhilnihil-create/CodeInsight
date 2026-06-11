#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

template <class abel> struct WUFT {
private:
	vector<int> par, rank;
	vector<abel> d_w;
	void init(int n = 1, abel su = 0) {
		par.resize(n); rank.resize(n); d_w.resize(n);
		for (int i = 0; i < n; i++)par[i] = i, rank[i] = 0, d_w[i] += su;
	}
	int root(int x) {
		if (par[x] == x)return x;
		else {
			int r = root(par[x]);
			d_w[x] += d_w[par[x]];
			return par[x] = r;
		}
	}
public:
	WUFT(int n = 1, abel su = 0) {
		init(n, su);
	}
	abel weight(int x) {
		root(x);
		return d_w[x];
	}
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
	bool merge(int x, int y, abel w = 1) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y)false;
		if (rank[x] < rank[y])swap(x, y), w = -w;
		if (rank[x] == rank[y])rank[x]++;
		par[y] = x;
		d_w[y] = w;
		return true;
	}
	abel diff(int x, int y) {
		return weight(y) - weight(x);
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	WUFT<ll> uft(N+1);
	bool flag = true;
	for (int i = 0; i < M; i++) {
		int L, R, D;
		cin >> L >> R >> D;
		if (uft.issame(L, R)) {
			if (uft.weight(R) - uft.weight(L) != D) {
				flag = false;
			}
		}
		else {
			uft.merge(L, R, D);
		}
	}
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}