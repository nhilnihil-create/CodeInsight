//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const ll MAXN = 4 * 100 * 1000 + 17, mod = 998244353;

int sum(int a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	else if (a < 0)
		a += mod;
	return a;
}

int mul(int a, int b) {
	return (1LL * a * b) % mod;
}

int pw(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

ll n, a, b, k, fac[MAXN], ifac[MAXN], ans;

void prep() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fac[i] = mul(fac[i - 1], i);
	for (int i = 0; i < MAXN; i++)
		ifac[i] = pw(fac[i], mod - 2);
}

int C(int x, int y) {
	return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> k;
	prep();
	for (int i = 0; i <= n; i++) {
		ll kp = k - i * a;
		if (kp >= 0 && kp % b == 0 && kp / b <= n)
			ans = sum(ans, mul(C(n, i), C(n, kp / b)));
	}
	cout << ans << endl;
	return 0;
}
