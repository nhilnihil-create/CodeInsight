#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

long long mypow(long long k, long long n) {
	long long temp = 1;

	k = k % DIV;
	while (n) {
		if (n % 2) temp = temp * k % DIV;
		k = k * k % DIV;
		n = n / 2;
	}
	return temp % DIV;
}

ll mul(ll a, ll b) {
	return ((a % DIV) * (b % DIV)) % DIV;
}

int main() {
	ll N, A, B, K; cin >> N >> A >> B >> K;
	int M = 3e5;
	vector<ll> f(M + 1), invf(M + 1);
	f[0] = 1, invf[0] = 1;
	for (int i = 1; i <= M; i++) {
		f[i] = f[i - 1] * i;
		f[i] %= DIV;
		invf[i] = mypow(f[i], DIV - 2);
		//if(i<=10)
		//cout << "i=" << i << " f[i]=" << f[i] << endl;
	}

	ll ans = 0;
	for (ll i = 0; i <= N; i++) {
		if (K - i * A >= (ll)0 && (K - i * A) % B == (ll)0) {
			ll j = (K - i * A) / B;
			if (j > N)continue;
			ll temp = mul(f[N], invf[i]);
			temp = mul(temp, invf[N - i]);
			temp = mul(temp, f[N]);
			temp = mul(temp, invf[j]);
			temp = mul(temp, invf[N - j]);
			//ans += (((f[N] * invf[i]) % DIV * ((invf[N - i] * f[N])) % DIV) % DIV * (f[j] * f[N - j]) % DIV) % DIV;
			ans += temp;
			ans %= DIV;
			//cout << "i=" << i <<" j="<<j<<" ans="<<ans<< endl;
		}
	}
	cout << ans << endl;
}