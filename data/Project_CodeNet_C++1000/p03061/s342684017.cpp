#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5;
int n, a[nm], l[nm], r[nm], ans;

int gcd(int a, int b) {
	if (!(a % b))
		return b;
	return gcd(b, a % b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	l[0] = a[0];
	for (int i = 1; i < n; i++)
		l[i] = gcd(l[i - 1], a[i]);

	r[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		r[i] = gcd(r[i + 1], a[i]);

	ans = max(l[n - 2], r[1]);
	for (int i = 1; i < n - 1; i++)
		ans = max(ans, gcd(l[i - 1], r[i + 1]));
	cout << ans << endl;
}
