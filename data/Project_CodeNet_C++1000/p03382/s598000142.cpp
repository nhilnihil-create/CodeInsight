#include <bits/stdc++.h>

using namespace std;
 
const int MaxN = (int)1e5 + 10;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

int a[MaxN];

int main() {
//	freopen("input.txt", "r", stdin);
//	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	scanf("%d", &n);
	int mx = 0, mn = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	mn = mx;
	for (int i = 1; i <= n; ++i) {
		if (mn == mx || abs(2 * a[i] - mx) < abs(2 * mn - mx)) {
			mn = a[i];
		}
	}
	cout << mx << ' ' << mn << '\n';
	return 0;
} 
