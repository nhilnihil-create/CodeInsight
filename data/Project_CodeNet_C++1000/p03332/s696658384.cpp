#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 10;
const int MOD = 998244353;

inline int inc(int a, int b) { return (a + b >= MOD) ? (a + b - MOD) : (a + b); }
inline int dec(int a, int b) { return (a >= b) ? (a - b) : (a + MOD - b); }
inline int mul(int a, int b) { return 1LL * a * b % MOD; }

inline int power(int x, int k) {
	int tmp = 1;
	while(k) {
		if(k & 1) tmp = mul(tmp,x);
		x = mul(x,x); 
		k >>= 1;
	}
	return tmp;
}

int n, a, b, fac[maxn], ifac[maxn];
ll k;

inline int C(int n, int m) {
	if(n < 0 || m < 0 || n < m) return 0;
	return mul(fac[n],mul(ifac[m],ifac[n - m]));
}

int main() {
  scanf("%d%d%d%lld", &n, &a, &b, &k);
	int Ans = 0;
	fac[0] = ifac[0] = 1;
	for(int i = 1;i <= n;i ++) fac[i] = mul(fac[i - 1],i);
	ifac[n] = power(fac[n],MOD - 2);
	for(int i = n - 1;i >= 1;i --) ifac[i] = mul(ifac[i + 1],i + 1);
	for(int z = 0;z <= n;z ++) {
    ll now = k - (ll)z * a;
		if(now % b != 0) continue;
		int y = now / b;
		if(now < 0 || y > n) continue;
		Ans = inc(Ans,mul(C(n,z),C(n,y)));
	}
	printf("%d\n", Ans);
	return 0;
}
