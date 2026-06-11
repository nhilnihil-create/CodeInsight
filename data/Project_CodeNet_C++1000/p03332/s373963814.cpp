#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 998244353;

ll N, A, B, K, a, b, x;
ll nCk[300010];

ll mp(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b % 2)
			ans *= a;
		a *= a;
		a %= MOD;
		ans %= MOD;
		b /= 2;
	}
	return ans;
}

//mod割り算
ll moddiv(ll a, ll b) {
	a %= MOD;
	return (a*mp(b, MOD - 2)) % MOD;
}

int main(){
	
	cin >> N >> A >> B >> K;

	nCk[0] = 1;
	for (int i = 1;i <= N;i++) {
		nCk[i] = moddiv(nCk[i - 1] * (N + 1 - i) % MOD, i);
	}

	ll ans = 0;
	for (int i = 0;i <= N;i++) {
		if ((K - i * A) % B == 0) {
			a = i, b = (K - i * A) / B;
			if (b > N || b < 0)continue;
			ans += nCk[a] * nCk[b];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}