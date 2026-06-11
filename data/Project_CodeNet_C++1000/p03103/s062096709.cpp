#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N, M; cin >> N >> M;
	vector<pair<ll, ll>> d(N);

	rep(i, N)cin >> d[i].first >> d[i].second;

	sort(d.begin(), d.end());

	ll ans = 0;
	ll cnt = 0;

	for (auto x : d) {
		ll n = min(x.second, M - cnt);
		cnt += n;
		ans += n * x.first;
		if (cnt >= M)break;
	}

	cout << ans << endl;

	return 0;
}