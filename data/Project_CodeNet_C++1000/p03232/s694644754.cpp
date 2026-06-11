#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int n;
long long a[maxn];
long long fact[maxn], inv[maxn];
long long val[maxn];

void brute() {
    int id[n], cnt[n];
    for (int i = 0; i < n; i++) id[i] = i, cnt[i] = 0;
    int vs[n];
    int ans = 0;
    do {
	for (int i = 0; i < n; i++) vs[i] = 0;
	for (int i = 0; i < n; i++) {
	    int cur = id[i];
	    while (cur < n && !vs[cur]) {
		ans += a[cur + 1];
		cnt[cur]++;
		cur++;
	    }
	    cur = id[i] - 1;
	    while (cur >= 0 && !vs[cur]) {
		ans += a[cur + 1];
		cnt[cur]++;
		cur--;
	    }
	    vs[id[i]] = 1;
	}
    } while (next_permutation(id, id + n));
    for (int i = 0; i < n; i++) {
	cout << cnt[i] << ' ';
    }
    cout << endl;
    cout << ans << endl;
}

long long power_mod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
	if (b % 2) res = res * a % mod;
	a = a * a % mod;
	b >>= 1;
    }
    return res;
}

long long C(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv[n - k] % mod * inv[k] % mod;
}

int main() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < maxn; i++) {
	fact[i] = fact[i - 1] * i % mod;
	inv[i] = power_mod(fact[i], mod - 2, mod);
    }

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
	val[i] = C(n, i + 1) * fact[i] % mod * fact[n - i - 1] % mod;
    }

    long long cur = 0;
    for (int i = 0; i < n; i++) {
	cur = (cur + val[i]) % mod;
    }

    long long ans = 0;
    for (int i = n; i >= 1; i--) {
	ans = (ans + cur * a[i - 1]) % mod;
	cur = (cur - val[i - 1] + val[n - i + 1] + mod) % mod;
    }

    cout << ans;

    return 0;
}
