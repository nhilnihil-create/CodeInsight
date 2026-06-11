#include <iostream>
#include <vector>
#define neparan & 1
using namespace std;

const int mod = 998244353;

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mul(int a, int b) {
	return ((long long)a * b) % mod;
}

int po(int a, int b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	if(b neparan) return mul(po(a, b - 1), a);
	int x = po(a, b / 2);
	return mul(x, x);
}

int dj(int a, int b) {
	return mul(a, po(b, mod - 2));
}

int fa[500000];

int ovrh(int n, int k) {
	return dj(fa[n], mul(fa[k], fa[n - k]));
}

int main() {
	
	fa[0] = 1;
	for(int i = 1; i < 500000; i++) {
		fa[i] = mul(fa[i - 1], i);
	}
	
	long long n, a, b, k;
	cin >> n >> a >> b >> k;
	
	int re = 0;
	
	for(int ca = 0; ca <= n; ca++) {
		long long umn = a * ca;
		if(umn <= k) {
			long long mcb = k-umn;
			if(mcb % b == 0) {//add(mul(ca, a), mul(cb, b)) == k) {
				long long cb = mcb / b;
				if (cb > n) continue;
				re = add(re, mul(ovrh(n, ca), ovrh(n, cb)));
			}
			//cout << k << ' ' << umn << '\n';
		}
	}
	
	cout << re;
	
	return 0;
}