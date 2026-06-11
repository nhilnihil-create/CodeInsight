#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 100005;

int n;
int a[N], l[N], r[N], m[N];

int main() {

	FAST;

	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	l[0] = 0;
	for (int i = 1; i <= n; i ++) {
		l[i] = __gcd(l[i - 1], a[i - 1]);
	}
	r[n + 1] = 0;
	for (int i = n; i >= 1; i --) {
		r[i] = __gcd(r[i + 1], a[i + 1]);
	}
	for (int i = 1; i <= n; i ++) {
		m[i] = __gcd(l[i], r[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans = max(ans, m[i]);
	}
	cout << ans << '\n';
	return 0;
}
