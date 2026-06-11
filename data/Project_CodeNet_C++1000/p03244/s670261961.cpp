#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	map<int, int> cnt1, cnt2;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i % 2 == 1) {
			cnt1[x]++;
		}
		else {
			cnt2[x]++;
		}
	}	
	int mx1 = 0, mx2 = 0, mx11 = 0, mx22 = 0;
	int x1 = -1, x2 = -1;
	for (auto x : cnt1) {
		if (x.second >= mx1) {
			mx11 = mx1;
			x1 = x.first;
			mx1 = x.second;
		}
		else if (x.second > mx11) {
			mx11 = x.second;
		}
	}
	for (auto x : cnt2) {
		if (x.second >= mx2) {
			mx22 = mx2;
			x2 = x.first;
			mx2 = x.second;
		}
		else if (x.second > mx22) {
			mx22 = x.second;
		}
	}
	if (x1 != x2) cout << n - (mx1 + mx2);
	else {
		cout << n - max(mx1 + mx22, mx11 + mx2);
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