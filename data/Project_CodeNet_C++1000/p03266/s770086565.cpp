
// C - Triangular Relationship

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N, K;
	cin >> N >> K;

	ll ans;

	if (K % 2 == 1) {
		ans = pow(N / K, 3);
	} else {
		int m = K / 2;
		int t = N / K;
		if (N % K >= m) t++;
		ans = pow(N / K, 3) + pow(t, 3);
	}

	cout << ans << endl;

	return 0;
}