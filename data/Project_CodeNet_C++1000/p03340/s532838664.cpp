
// D - Xor Sum 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll cum_sum[200001];
ll cum_xor[200001];
ll A[200000];

bool is_ok(ll i, ll j) {
	return (cum_sum[j+1] - cum_sum[i]) == (cum_xor[j+1] ^ cum_xor[i]);
}

// [lower, upper) の範囲でis_ok()を満たすような上限のi（存在しない場合は-1）を返す
//   lower: 最小のインデックス
//   upper: 最大のインデックス + 1
ll find_max_ok(ll lower, ll upper) {
	ll ok = lower;
	ll ng = upper;

	while(ng - ok > 1) {
		ll trying = (ng + ok) / 2;

		if (is_ok(lower, trying)) {
			ok = trying;
		} else {
			ng = trying;
		}
	}

	return ok;
}

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=0; i<N; i++) {
		cum_sum[i+1] = cum_sum[i] + A[i];
		cum_xor[i+1] = cum_xor[i] ^ A[i];
	}

	ll ans = 0;

	for (int i=0; i<N; i++) {
		ans += find_max_ok(i, N) - i + 1;
	}

	cout << ans << endl;

	return 0;
}