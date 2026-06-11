#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353, MAXN = 300 * 1000 + 100;
int n, a, b, tav2[MAXN], fact[MAXN], inv[MAXN];
ll k;

int efraz(int a, ll b);
int RGB_Coloring();
void PreWorks();
int power(int a, int b);
int chose(int k, int n);

int main() {
	PreWorks();
	cin >> n >> a >> b >> k;
	cout << RGB_Coloring();
}

int power(int a, int b) {
	if (!b)
		return 1;
	int t = power(a, b / 2);
	return b % 2? (ll)t * t % MOD * a % MOD: (ll)t * t % MOD;
} 

void PreWorks() {
	fact[0] = 1;
	inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = (ll)fact[i - 1] * i % MOD;
		inv[i] = power(fact[i], MOD - 2);
	}
}

int efraz(int a, ll k) {
	if (k < 0)
		return 0;
	if (k % a)
		return 0;
	ll p = k / a;
	if (p > n)
		return 0;
	return (ll)chose(p, n);
}

int RGB_Coloring() {
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		ll p = k - (ll)i * a;
//		cerr << b << ' ' << p << ' ' << efraz(b, p) << endl;
		ans += (ll)efraz(b, p) * chose(i, n) % MOD;
		ans %= MOD;
	}
	return ans;
}

int chose(int k, int n) {
	return (ll)fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}
