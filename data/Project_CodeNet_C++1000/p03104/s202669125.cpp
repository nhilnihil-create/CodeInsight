
// D - XOR World

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll g(ll k) {
	ll result = 0;
	for (int i=1; i<63; i++) {
		ll p = pow(2, i);
		ll n = (k + 1) / p * p / 2 + max(0LL, ((k + 1) % p) - p / 2);
		//cout << n << " " << (n % 2) * pow(2, i-1) << endl; // **** debug ****
		result += (n % 2) * pow(2, i-1);
	}
	//cout << k << " : " << result << endl; // **** debug ****
	return result;
}

ll f(ll A, ll B) {
	return g(B) ^ g(max(0LL, A-1));
}

int main() {
	ll A, B;
	cin >> A >> B;

	ll ans = f(A, B);

	cout << ans << endl;

	return 0;
}