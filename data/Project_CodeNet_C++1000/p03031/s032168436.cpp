#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p[11], s[11];
vector<int> a[11];
int res = 0;
void check() {
	for (int i = 1; i <= m; i++) {
		int cnt = 0;
		for (auto x : a[i]) {
			cnt += s[x];
		}
		if (cnt % 2 != p[i]) {
			return;
		}
	}
	res += 1;
}

void find(int p = 1) {
	if (p > n) {
		check();
		return;
	}
	s[p] = 1;
	find(p + 1);
	s[p] = 0;
	find(p + 1);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int f;
			cin >> f;
			a[i].push_back(f);
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}
	find();
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}