#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
typedef long long LL;

int n;
LL a, b, c, d, e, ans, k, mod = 998244353, fac[N], inv[N];

LL calc(LL a, LL b) {
	return fac[a]*inv[b]%mod*inv[a - b]%mod;
}

LL fsp(LL a, LL b) {
	LL res = 1;
	while(b) {
		if(b&1) res = res*a%mod;
		b /= 2;
		a = a*a%mod;
	}
	return res;
}

int main() {
	cin>>n>>a>>b>>k;
	c = a + b;
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1]*i%mod;
		inv[i] = fsp(fac[i], mod - 2);
	}
	for(int i = 0; i <= n && i*a <= k; i++) {
		if((k - a*i)%b != 0) continue;
		LL j = (k - a*i)/b;
		if(j > n) continue;
		ans = (ans + calc(n, i)*calc(n, j))%mod;
	}
	cout<<ans<<endl;
	return 0;
}