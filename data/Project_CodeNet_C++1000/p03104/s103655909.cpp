
// D - XOR World

// 任意の偶数 n について n ⊕ (n + 1) = 1 を利用した解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll g(ll k) {
	if (k == 0) {
		return 0;
	} else if (k % 2 == 0) {
		return 1 ^ (((k - 2) / 2) % 2) ^ k;
	} else {
		return 1 ^ (((k - 1) / 2) % 2);
	}
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