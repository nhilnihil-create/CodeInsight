#include <iostream>
#include <cstdio>
#define N 300005
using namespace std;

typedef long long ll;
ll fac[N]={1,1}, inv[N]={1,1}, fiv[N]={1,1};
ll n, M = 998244353, A, B, k, ans;

ll c(ll p) {return fac[n] * fiv[n-p] % M * fiv[p] % M;}

int main()
{
	ll i, j;
	cin >> n >> A >> B >> k;
	for(i=2; i<=n; i++) {
		fac[i] = fac[i-1] * i % M;
		inv[i] = inv[M%i] * (M-M/i) % M;
		fiv[i] = fiv[i-1] * inv[i] % M;
	}
	for (i = 0; i * A <= k && i <= n; i++) {
		if ((k - i * A) % B) continue;
		j = (k - i * A) / B;
		if (j <= n) ans = (ans + (c(i) * c(j)) % M) % M;
	}
	cout << ans;
    return 0;
}
