#include <bits/stdc++.h>
#define PII pair<int, int>
#define LL long long
using namespace std;
const int MAXN = 100005;
const int INF = (LL)1e9 + 5;
const LL MOD = 1000000007;

LL mod_inv(LL a) {
	LL pw = MOD - 2, res = 1;
	while (pw) {
		if (pw & 1) res = res * a % MOD;
		pw >>= 1;
		a = a * a % MOD;
	}
	return res;
}

int N;
LL sum[MAXN], pref[MAXN], fac = 1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pref[i];
		pref[i] = (pref[i - 1] + pref[i]) % MOD;
		fac = (fac * i) % MOD;
	}
	
	sum[1] = pref[N];
	for (int i = 2; i <= N; i++) {
		sum[i] = (sum[i - 1] + pref[N - i + 1] - pref[i - 1]) % MOD;
//		cout << i << " -> " << sum[i] << '\n';
	}
	
	LL ans = 0;
	for (int i = 1; i < N; i++) {
//		cout << i << " add " << (sum[i] - pref[i] - (pref[N] - pref[N - i])) << " mul " << mod_inv((LL) (i + 2) * (i + 1) % MOD) * fac % MOD << '\n';
		ans = (ans + (sum[i] - pref[i] - (pref[N] - pref[N - i])) % MOD * 2 * mod_inv((LL) (i + 2) * (i + 1) % MOD)) % MOD;
	}
	
	ans = (ans + pref[N]) % MOD;
	for (int i = 1; i < N; i++) {
		LL s = pref[i];
//		cout << "Pref " << i << " add " << s << ' ' << fac * mod_inv(i + 1) % MOD << '\n';
		ans += s * mod_inv(i + 1);
		ans %= MOD;
	}
	for (int i = 2; i <= N; i++) {
		LL s = (pref[N] - pref[i - 1]) % MOD;
//		cout << "suff " << i << " add " << s << ' ' << fac * mod_inv(N - i + 2) % MOD << '\n';
		ans += s * mod_inv(N - i + 2);
		ans %= MOD;
	}
	
	cout << (ans * fac % MOD + MOD) % MOD << '\n';

	return 0;
}