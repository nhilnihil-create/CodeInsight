#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	map<int, int> m;
	int s = 0;
	for (int i = 0; i <= n; i++) {
		int t = abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]);
		m[i + 1] = t;
		s += abs(a[i] - a[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		int t = s - m[i] + abs(a[i - 1] - a[i + 1]);
		cout << t << '\n';
	}
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