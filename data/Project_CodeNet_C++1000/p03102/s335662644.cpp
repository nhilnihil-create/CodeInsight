#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n, m, c, a[100][100], b[100], ans, total;
int32_t main() {
	total = 0;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> c;
	for(int i = 0; i < m; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; ++i) {
		ans = 0;
		for(int j = 0; j < m; ++j) {
			ans += a[i][j]*b[j];
		}
		if (ans+c > 0) ++total;
	}
	cout << total;
}