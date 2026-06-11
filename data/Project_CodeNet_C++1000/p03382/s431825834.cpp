#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;
int n, ar[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	
	int x = ar[n - 1], mn = abs(x / 2 - ar[0]), ans = ar[0];
	for (int i = 0; i < n - 1; i++)
		if (abs((x + 1) / 2 - ar[i]) < mn)
			mn = abs((x + 1) / 2 - ar[i]), ans = ar[i];
	cout << x << ' ' << ans << endl;
}