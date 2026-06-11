#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 0; i < n; ++i) cin >> a[i];

	a[n] = -1;

	int cnt = 1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[i + 1]) {
			ans += cnt / 2;
			cnt = 1;
		}
		else cnt++;
	}
	cout << ans << endl;
	return 0;
}