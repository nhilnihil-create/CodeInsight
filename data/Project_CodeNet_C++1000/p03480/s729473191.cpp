
// D - Wide Flip

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

string S;

bool is_ok(int K) {
	int N = S.size();
	int l = N - K;
	int r = K - 1;

	bool ok = true;
	for (int i=l; i<r; i++) {
		if (S[i] != S[i+1]) {
			ok = false;
			break;
		}
	}

	return ok;
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
	cin >> S;

	ll K = find_max_ok(1, S.size() + 1);

	cout << K << endl;

	return 0;
}