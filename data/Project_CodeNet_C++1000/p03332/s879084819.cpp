#include <bits/stdc++.h>
using namespace std;

int n, a, b;
long long k;
const int MOD = 998244353;
int f[300010];

int add(int a, int b) {
	return ((long long) a + b) % MOD;
}

int mul(int a, int b) {
	return ((long long) a * b) % MOD;
}

int pot(int x, int y) {
	int out = 1, pr = x;
	while (y) {
		if (y & 1) out = mul(out, pr);
		pr = mul(pr, pr);
		y /= 2;
	}
	return out;
}

int main () {
	
	cin >> n >> a >> b >> k;
	long long int sol = 0;
	f[0] = 1;
	for (int i = 1; i <= n; i ++) {
		f[i] = mul(f[i-1], i);
	}
	
	for (int i = 0; i <= n; i ++) {
		long long int tren = k;
		tren -= i * a;
		if (tren < 0 || tren % b != 0) continue;
		tren /= b;
		if (tren > n) continue;
		long long int sad = mul(f[n], pot(mul(f[i], f[n-i]), MOD-2));
		sad = mul(sad, mul(f[n], pot(mul(f[tren],f[n-tren]), MOD-2)));
		
		sol += sad;
		sol %= MOD;
	}
	
	cout << sol;

	return 0;
}