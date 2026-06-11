#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int sub(int a, int b) {
	return (a - b + MOD) % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int divv(int a, int b) {
	return mul(a, binpow(b, MOD - 2));
}

int f[N];
int ps[N];

void init() {
	f[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = mul(i, f[i - 1]);
	}
	ps[0] = 0;
	for (int i = 1; i < N; i++) {
		ps[i] = ps[i - 1] + divv(1, i);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	init();

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	int ans = 0; 
	for (int i = 0; i < n; i++) {
		int c = 0;
		c = ps[i + 1];
		c = add(c, ps[n - i]);
		c = sub(c, 1);
		c = mul(c, f[n]);
		ans = add(ans, mul(a[i], c));
	}
	cout << ans << endl;
}	
