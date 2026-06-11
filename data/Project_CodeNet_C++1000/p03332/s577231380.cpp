#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 998244353;
const int N = 3e5 + 5;

int n;
LL a, b, k, ans, fac[N], inv[N];

LL Ksm(LL a, LL b) {
	LL res = 1;
	while(b) {
		if(b&1) res = res*a%mod;
		b /= 2;
		a = a*a%mod;
	}
	return res;
}

LL cal(int n, int k) {
	return fac[n]*inv[k]%mod*inv[n - k]%mod;
}

int main() {
	cin>>n>>a>>b>>k;
	fac[0] = inv[0] = 1;
	rep(i, 1, n) fac[i] = fac[i - 1]*i%mod, inv[i] = Ksm(fac[i], mod - 2);
	rep(i, 0, n) {
		if(a*i > k) break;
		if((k - a*i)%b) continue;
		if((k - a*i)/b > n) continue;
		int t = (k - a*i)/b;
		ans = (ans + cal(n, t)*cal(n, i)%mod)%mod;
	}
	cout<<ans<<endl;
}