#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
ll A[2000];
int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll ans = INF;
	for (int i = 0; i < N; i++) {
		ll l = -1, r = INF;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			int cnt = 0;
			int len = 0, a = 0, b = 0;
			for (int j = 0; j < N; j++) {
				if (A[j] < A[i]) {
					cnt += min(max(len - K + 1, 0), a);
					len = a = b = 0;
				}
				else {
					len++;
					if (A[j] <= A[i] + m) a++;
					else b++;
				}
			}
			cnt += min(max(len - K + 1, 0), a);
			if (cnt >= Q) r = m;
			else l = m;
		}
		ans = min(ans, r);
	}
	cout << ans << endl;
}
