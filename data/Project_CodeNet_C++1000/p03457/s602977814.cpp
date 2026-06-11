#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100500][3];
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int x = 0, y = 0, t = 0;
	for (int i = 0; i < n; i++) {
		int time = a[i][0] - t;
		int s = abs(x - a[i][1]) + abs(y - a[i][2]);
		if (time == s || (time > s && (time - s) % 2 == 0)) {
			t = a[i][0];
			x = a[i][1];
			y = a[i][2];
		}
		else {
			cout << "No";
			return;
		}
	}
	cout << "Yes";
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