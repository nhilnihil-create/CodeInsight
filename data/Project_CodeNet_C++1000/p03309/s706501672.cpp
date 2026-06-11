
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
ll A[200000];

ll err(int k) {
	ll result = 0;

	for (int i=0; i<N; i++) {
		result += abs(A[i] - (k + i + 1));
	}

	return result;
}

bool is_ok(int b) {
	return (err(b-1) >= err(b));
}

ll find_max_ok(ll lower, ll upper) {
	if (!is_ok(lower)) return -1; // 存在しない

	ll ok = lower;
	ll ng = upper;

	while(ng - ok > 1) {
		ll trying = (ng + ok) / 2;

		if (is_ok(trying)) {
			ok = trying;
		} else {
			ng = trying;
		}
	}

	return ok;
}

int main() {
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	ll b = find_max_ok(-1000000000, 1000000000);

	ll ans = err(b);

	cout << ans << endl;

	return 0;
}