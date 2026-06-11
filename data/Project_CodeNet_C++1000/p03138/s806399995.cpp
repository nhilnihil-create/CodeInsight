#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

	ll N, K;
	cin >> N >> K;

	ll ans = 0;

	vector<ll> A(N);

	for(int i = 0; i < N; i++) {
		cin >> A[i];
		ans += A[i];
	}

	ll count = 0;

	for(ll i = 45; i >= 0; i--) {
		ll x = 1LL << i;
		if(count + x > K) continue;
		ll c = 0;
		for(int j = 0; j < N; j++) {
			if(A[j] & x) {
				c++;
			}
		}
		c = N - c;
		//cerr << c << endl;
		if(c > N / 2LL) {
			count += x;
			ans += x * (2LL * c - N);
		}
	}

	cout << ans << endl;
}