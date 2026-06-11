#include<bits/stdc++.h>
using namespace std;

int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int L; cin >> L;
	int n = 32 - __builtin_clz(L);
	vector< tuple<int, int, int> > V;
	for(int i = 1; i + 1 <= n; i++) {
		V.emplace_back(i, i + 1, 1 << (n - 1 - i));
		V.emplace_back(i, i + 1, 0);
	}
	while(L & (L - 1)) {
		int t = L & -L;
		L = L & (L - 1);
		int ctz = __builtin_ctz(t);
		V.emplace_back(1, n - ctz, L);
	}
	cout << n << ' ' << V.size() << '\n';
	for(auto &e : V) {
		int u, v, w;
		tie(u, v, w) = e;
		cout << u << ' ' << v << ' ' << w << '\n';
	}
	return 0;
}
