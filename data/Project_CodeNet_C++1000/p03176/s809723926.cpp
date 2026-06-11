/*
─────────────────────
───────────████████──
──────────███▄███████
──────────███████████
──────────███████████
──────────██████─────
──────────█████████──
█───────███████──────
██────████████████───
███──████AJ████──█───
███████████████──────
███████████████──────
─█████████████───────
──███████████────────
────████████─────────
─────███──██─────────
─────██────█─────────
─────█─────█─────────
─────██────██────────
─────────────────────
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

int N;
vector<ll> b;
vector<ll> h;
// ll result = 0;
// const int maxN = 1e5 + 1;

ll solve() {
	vector<ll> dp(N);
	map<ll, ll> map; //height to dp
	dp[0] = b[0];
	map[h[0]] = b[0];
	ll ans = dp[0];
	// cout << N << endl;
	for (int i = 1; i < N; i++) {
		// cout << i << endl;
		dp[i] = b[i];
		auto it = map.lower_bound(h[i] + 1);
		if (it != map.begin()) {
			// cout << "Entered\n";
			it--;
			// dp[i] = max(dp[i], )
			dp[i] += it->second;
		}
		map[h[i]] = dp[i];
		it = map.upper_bound(h[i]);
		// it++;
		while (it != map.end() && it->second <= dp[i]) {
			// cout << "Deleted\n";
			auto temp = it;
			temp++;
			map.erase(it);
			it = temp;
		}
		// cout << dp[i] << endl;
		ans = max(ans, dp[i]);
		// printf("dp[i]: %lld, ans: %lld\n", dp[i], ans);
	}
	// for (auto x : dp) {
	// 	cout << x << " ";
	// }
	// cout << endl;
	return ans;
}

int main() {
	cin >> N;
	b = vector<ll>(N);
	h = vector<ll>(N);
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	ll res = solve();
	cout << res << endl;
	return 0;
}