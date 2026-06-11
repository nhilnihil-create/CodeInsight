#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = abs(a[i] - x);
	}
	int ans = a[0];
	for (int i = 0; i < n; i++) {
		ans = __gcd(ans, a[i]);
		if (ans == 1)
			return cout << 1, 0;
	}
	cout << ans << endl;
	return 0;
}
