#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<long long, long long> > prime_factorize(long long N) {
	vector<pair<long long, long long> > res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // 指数

		 // 割れる限り割り続ける
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// その結果を push
		res.push_back({ a, ex });
	}

	// 最後に残った数について
	if (N != 1) res.push_back({ N, 1 });
	return res;
}

int main() {
	
	ll n; cin >> n;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (i % 2 == 0) continue;
		vector<pair<long long, long long>> a_prime;  // a^x ならば { a, x }
		a_prime = prime_factorize(i);
		ll tmp = 1;
		for (int j = 0; j < a_prime.size(); j++) {
			tmp *= a_prime[j].second + 1;
		}
		if (tmp == 8) ans++;
	}
	cout << ans << endl;
	return 0;
}