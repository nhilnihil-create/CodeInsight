#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}
	long long int ans = 0;
	vector<long long int>by(N + 1, 1);
	for (long long int i = 1; i <= N; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
	}
	ans = v[N];
	ans %= MOD;
	ans *= by[N];
	ans %= MOD;
	for (int i = N - 1; i >= 1; i--) {
		long long int box = v[i];
		box += v[N];
		box -= v[N - i];
		box %= MOD;
		box *= by[N];
		box %= MOD;
		box *= power(by[i + 1], MOD - 2, MOD);
		box %= MOD;
		box *= power(by[N - i - 1], MOD - 2, MOD);
		box %= MOD;
		box *= by[i];
		box %= MOD;
		box *= by[N - i - 1];
		box %= MOD;
		ans += box;
		ans %= MOD;
	//	cout << ans << endl;
	}
	long long int box = v[N - 1];
	box -= v[1];
	box %= MOD;
//	cout << ans << endl;
	for (int i = 1; i <= (N - 1) / 2; i++) {
		long long int a = i;
		long long int b = 2;
		long long int bag = box;
		bag *= by[N];
		bag %= MOD;
		bag *= by[b];
		bag %= MOD;
		bag *= by[a];
		bag %= MOD;
		bag *= power(by[a + b], MOD - 2, MOD);
		bag %= MOD;
		ans += bag;
		ans %= MOD;
		if (a == N - 1 - a)continue;
		a = N - 1 - a;
		bag = box;
		bag *= by[N];
		bag %= MOD;
		bag *= by[b];
		bag %= MOD;
		bag *= by[a];
		bag %= MOD;
		bag *= power(by[a + b], MOD - 2, MOD);
		bag %= MOD;
		ans += bag;
		ans %= MOD;
		box += v[N - 1 - i];
		box -= v[i + 1];
		box %= MOD;
	}
	cout << ans << endl;
	return 0;
}
