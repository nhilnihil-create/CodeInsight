
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)
#define IN(i,a,b) (a<=i&&i<=b)

const ll mod = 998244353;

ll modpow(ll a, ll b) {
	return b?modpow(a*a%mod,b/2) * (b&1?a:1) % mod:1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; ll a,b; ll K;
	cin>>n>>a>>b>>K;
	ll fac[n+1], inv[n+1];
	f(i,0,n+1) fac[i] = i?fac[i-1]*i%mod:1;
	inv[n] = modpow(fac[n],mod-2);
	fr(i,0,n) inv[i] = inv[i+1]*(i+1)%mod;
	function<ll(int)> ncr = [&](int r) {
		if (r<0||r>n) return 0;
		return int(fac[n]*inv[r]%mod*inv[n-r]%mod);
	};
	ll ans = 0;
	f(k,0,n+1) if (a*k<=K){
		ll kp = (K-a*k)/b;
		if (a*k+b*kp != K)
			continue;
		ans = (ans+1LL*ncr(k)*ncr(kp)%mod)%mod;
	}
	cout << ans << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

