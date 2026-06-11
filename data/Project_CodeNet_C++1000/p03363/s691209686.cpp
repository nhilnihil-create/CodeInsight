#include <bits/stdc++.h>
using namespace std;

const int nm = 2e5;
int n, l = 0, r;
long long b[nm + 1], ans = 0;

int main() {
	cin >> n;
	r = n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		b[i + 1] = b[i] + a;
	}
	sort(b, b + n + 1);
	for (int i = 0, c = 1; i < n + 1; i++) {
		if (i < n && b[i + 1] == b[i]) {
			c++;
		} else {
			ans += (long long) c * (c - 1) / 2;
			c = 1;
		}
	}
	cout << ans << endl;
}
