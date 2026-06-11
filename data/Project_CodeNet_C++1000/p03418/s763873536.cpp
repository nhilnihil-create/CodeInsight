
// D - Remainder Reminder

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;

	ll ans = 0;

	for (int b=K+1; b<=N; b++) {
		//cout << "b=" << b << " "; // **** debug ****
		ll a1 = N / b * max(0, b - K);
		ll a2;
		if (N % b > 0) {
			if (K == 0) a2 = N % b;
			else a2 = max(0, (N % b) - K + 1);
		} else {
			a2 = 0;
		}
		ans += a1 + a2;
		//cout << "a1=" << a1 << " " << "a2=" << a2 << endl; // **** debug ****
	}

	cout << ans << endl;

	return 0;
}