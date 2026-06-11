#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 5, mod = 998244353;

typedef long long ll;
typedef long double ld;

ll fact[N], rev[N];

ll pw(ll a, ll b) {
	if(!b)	return 1LL;
	ll ans = pw(a, b / 2);
	ans *= ans;
	ans %= mod;
	if(b & 1)	ans *= a;
	return ans % mod;
}

void prep() {
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
	rev[N - 1] = pw(fact[N - 1], mod - 2);
	for (int i = N - 2; i; i--)
		rev[i] = (rev[i + 1] * (i + 1)) % mod;
	rev[0] = 1;
}

ll c(ll n, ll k) {
	ll ans = fact[n] * rev[k];
	ans %= mod;
	ans *= rev[n - k];
	return ans % mod;
}

int main() {
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	prep();
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll tmp = k - (i * a);
		if(tmp >= 0LL && tmp % b == 0 && tmp / b <= n) {
			tmp /= b;
			ans += c(n, i) * c(n, tmp);
			ans %= mod;
		}
	}
	cout << ans << "\n";
}