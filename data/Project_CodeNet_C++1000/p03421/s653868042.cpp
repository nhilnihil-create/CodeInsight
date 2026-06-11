#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, a, b; cin >> n >> a >> b;
	if (n > 1ll * a * b || a + b - 1 > n) {
		return cout << -1 << '\n',0;
	}
	vector<int> vans;
	for (int i = b; i >= 1; --i) {
		vans.push_back(i);
	}
	int cur = b + 1;
	int lef = n - b - (a - 1);
	for (int i = 1; i < a; ++i) {
		int go = min(b - 1, lef);
		for (int j = cur + go; j >= cur; --j) {
			vans.push_back(j);
		}
		lef -= go;
		cur += go + 1;
	}
	for (int x : vans) cout << x << ' ';
}