#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 998244353, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

ll arr[100000];
ll cnt[40];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K;
	rep(i, N) {
		cin >> arr[i];
		rep(j, 40) {
			if (((arr[i] >> j)%2) == 0) cnt[j]++;
		}
	}
	ll sum = 0;
	rep(i, 40) {
		if (N - cnt[i] < cnt[i]) {
			sum += (1ll << i);
		}
	}
	ll num = 0;
	bool flag = false;
	for (int i = 39; i >= 0; i--) {
		if (flag) {
			num += (((sum >> i)%2) << i);
			continue;
		}
		if ((sum >> i) % 2 == ((K >> i) % 2)) {
			num += (((K >> i) % 2) << i);
		}
		else if ((sum >> i) % 2 == 0) {
			num += (((sum >> i) % 2) << i);
			flag = true;
		}
	}
	ll ans = 0;
	rep(i, N) {
		ans += num ^ arr[i];
	}
	cout << ans;
}