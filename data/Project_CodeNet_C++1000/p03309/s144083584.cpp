#include <bits/stdc++.h>
#define LINF 1001001001001001001
typedef long long ll;
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] -= i + 1;
	}
	sort(a.begin(), a.end());
	int b;
	if (n % 2 == 0) {
		b = (a[n / 2] + a[n / 2 - 1]) / 2;
	} else {
		b = a[n / 2];
	}
	ll ans = 0;
	for (int j = 0; j < n; j++) {
		ans += abs(a[j] - b);
	}
	cout << ans << endl;
	return 0;
}