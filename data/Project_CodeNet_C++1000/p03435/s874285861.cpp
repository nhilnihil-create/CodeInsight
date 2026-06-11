#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[4][4];
void solve() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 2; i++) {
		int s1 = a[i][1] - a[i + 1][1];
		int s2 = a[i][2] - a[i + 1][2];
		int s3 = a[i][3] - a[i + 1][3];
		if (s1 != s2 || s1 != s3) {
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