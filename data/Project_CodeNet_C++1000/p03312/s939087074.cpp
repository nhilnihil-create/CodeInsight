#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	vector<ll> sum(N+1, 0);
	for(int i=1;i<=N;i++) sum[i] = sum[i-1] + A[i-1];

	ll ans = LLONG_MAX;
	// i番目のあとが真ん中の切れ目
	for(ll i=0;i<=N;i++) {
		// P, Qが一番近くなる切れ目を求める
		int low = 0, high = i;
		while(high - low > 1) {
			int mid = (high + low) >> 1;
			if(sum[mid] >= sum[i] - sum[mid]) high = mid;
			else low = mid;
		}
		ll P = sum[low], Q = sum[i] - sum[low];
		ll P2 = sum[high], Q2 = sum[i] - sum[high];
		ll left_min = min(P,Q), left_max = max(P,Q);
		if(llabs(P2-Q2) < llabs(P-Q)) {
			left_min = min(P2, Q2);
			left_max = max(P2, Q2);
		}

		// R, Sが一番近くなる切れ目を求める
		low = i+1, high = N;
		while(high - low > 1) {
			int mid = (high + low) >> 1;
			if(sum[mid] - sum[i] >= sum[N] - sum[mid]) high = mid;
			else low = mid;
		}
		ll R = sum[low] - sum[i], S = sum[N] - sum[low];
		ll R2 = sum[high] - sum[i], S2 = sum[N] - sum[high];
		ll right_min = min(R, S), right_max = max(R, S);
		if(llabs(R2-S2) < llabs(R-S)) {
			right_min = min(R2, S2);
			right_max = max(R2, S2);
		}

		ll tmp = max(left_max, right_max) - min(left_min, right_min);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}