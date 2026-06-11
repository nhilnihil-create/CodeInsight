#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i + 1])
			ans += a[i] - a[i + 1];
	}
	cout << ans << endl;
	return 0;
}
