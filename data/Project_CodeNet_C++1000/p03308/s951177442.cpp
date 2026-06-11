#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, a[100] = { 0 }, mi = 1000000000, ma = 0;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
	}
	cout << ma - mi << endl;
	return 0;
}