
// D - Cake 123

// 解説pdfの解法 #4

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll X, Y, Z, K;
ll A[1000], B[1000], C[1000];

// 美味しさの合計がP以上である個数がK個以上あるかどうかを判定
bool is_ok(ll P) {
	int cnt = 0;
	for (int i=0; i<X; i++) {
		for (int j=0; j<Y; j++) {
			for (int k=0; k<Z; k++) {
				if (A[i] + B[j] + C[k] < P) break;
				cnt++;
				if (cnt >= K) return true;
			}
		}
	}

	return false;
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
	cin >> X >> Y >> Z >> K;

	for (int i=0; i<X; i++) {
		cin >> A[i];
	}
	sort(A, A+X, greater<ll>());

	for (int i=0; i<Y; i++) {
		cin >> B[i];
	}
	sort(B, B+Y, greater<ll>());

	for (int i=0; i<Z; i++) {
		cin >> C[i];
	}
	sort(C, C+Z, greater<ll>());

	ll P = find_max_ok(0, INF); // 美味しさがP以上のものがK個までに含まれる

	vector<ll> ans;
	int cnt = 0;
	for (int i=0; i<X; i++) {
		for (int j=0; j<Y; j++) {
			for (int k=0; k<Z; k++) {
				if (A[i] + B[j] + C[k] < P + 1) break;
				ans.push_back(A[i] + B[j] + C[k]);
				cnt++;
			}
		}
	}

	sort(ans.begin(), ans.end(), greater<ll>());

	for (int i=0; i<K; i++) {
		if (i < cnt) cout << ans[i] << endl;
		else cout << P << endl;
	}

	return 0;
}