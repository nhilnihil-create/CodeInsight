#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100500];
void solve() {
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i + 1] - a[i];
	}
	sort(a, a + n - 1);
	int res = 0;
	for (int i = n - m - 1; i >= 0; i--) {
		res += a[i];
	}
	cout << res;
	// .   .      .         .            .                  .
	// 0   1      2         3            4
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