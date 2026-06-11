#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
const long long mod = 1000000007;

int modpow(int a, int x) {
	int res = 1;
	while (x) {
		if (x&1)res = res*a%mod;
		a = a*a%mod;
		x >>= 1;
	}
	return res;
}

signed main() {
	int r, g, b, n; cin >> r >> g >> b >> n;
	int sum = 0;

	for (int i = 0; i*r <= n; i++) {
		for (int j = 0; i*r + j*b <= n; j++) {
			int k = n - i*r - j*b;
			if (k%g == 0)sum++;
		}
	}
	cout << sum << endl;
}
