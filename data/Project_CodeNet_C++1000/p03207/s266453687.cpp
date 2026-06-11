#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)cin >> a[i];

	sort(a, a + n);
	int mx = a[n - 1];

	int s = 0;
	for (int i = 0; i < n - 1; i++) {
		s += a[i];
	}
	cout << s + mx / 2 << endl;

	return 0;
}