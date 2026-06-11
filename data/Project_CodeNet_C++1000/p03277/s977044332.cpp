#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;

const int maxn = 100101;
ll n, a[maxn], s[maxn], L, R, f[maxn * 2 + 10], b[maxn], c[maxn * 2 + 10];

void add(ll x) {
	while (x <= 2 * maxn)f[x]++, x += x & -x;
}
ll query(ll x) {
	ll tot = 0;
	while (x > 0)tot += f[x], x -= x & -x;
	return tot;
}

bool check(ll x) {
	memset(f, 0, sizeof f);
	for (ll i = 1; i <= n; i++) {
		if (a[i] >= x)c[i] = 1; else c[i] = -1;
		c[i] += c[i - 1];
	}
	ll ans = 0;
	for (ll i = 0; i <= n; i++)ans += (query(c[i] + maxn)), add(c[i] + maxn);
	return ans >= n * (n + 1) / 4 ? true : false;
}

int main() {
	cin >> n;
	for (ll i = 1; i <= n; i++)cin >> a[i], s[i] = a[i];
	sort(s + 1, s + n + 1);
	L = 1, R = n;
	while (L <= R) {
		ll mid = L + R >> 1;
		if (check(s[mid]))L = mid + 1; else R = mid - 1;
	}
	cout << s[R] << endl;
	return 0;
}