#include <bits/stdc++.h>
using namespace std;

struct Data {
	int u, v, w;
	Data(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
};

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int L; cin >> L;
	int n = 32 - __builtin_clz(L);
	vector<Data> edges;
	
	for (int i = 1; i < n; i++) {
		edges.emplace_back(i, i + 1, 1 << i - 1);
		edges.emplace_back(i, i + 1, 0);
	}
	int cur = 1 << n - 1;
	for (int i = n - 2; i >= 0; i--) if (L >> i & 1) {
		edges.emplace_back(i + 1, n, cur);
		cur |= 1 << i;
	}
	
	cout << n << " " << edges.size() << "\n";
	for (auto it : edges) cout << it.u << " " << it.v << " " << it.w << "\n";
	
	return 0;
}
