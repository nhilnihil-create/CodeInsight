
// D - Candy Distribution

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[100000];
ll cum_A[100001];
unordered_map<int, ll> mod_cnt;

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<N; i++) {
		cin >> A[i];
		cum_A[i+1] = cum_A[i] + A[i];
	}

	for (int i=0; i<=N; i++) {
		mod_cnt[cum_A[i] % M]++;
	}

	ll ans = 0;

	for (auto itr : mod_cnt) {
		ll cnt = itr.second;
		ans += cnt * (cnt - 1) / 2;
	}

	cout << ans << endl;

	return 0;
}