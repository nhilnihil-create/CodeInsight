#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int N;
vi W, S, V;
vector<pi> P;
vector<ll> dp;

void input_init(void) {
	cin >> N;
	W.resize(N);
	S.resize(N);
	V.resize(N);
	P.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> W[i] >> S[i] >> V[i];
		P[i] = make_pair(W[i] + S[i], i);
	}
}

ll solve(void) {
	ll ret = (ll)0;
	int sz = P[N - 1].first + 1;
	dp.resize(sz, (ll)0);
	for (int i = 0; i < N; ++i) {
		int id = P[i].second;
		for (int j = S[id]; j >= 0; --j) {
			ll val = dp[j] + V[id];
			ret = max(ret, val);
			if (j + W[id] <= sz)
				dp[j + W[id]] = max(dp[j + W[id]], val);
		}
	}
	return ret;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input_init();
	sort(P.begin(), P.end());
	ll ans = solve();

	cout << ans << '\n';
	return 0;
}
