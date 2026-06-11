#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, M;
	cin >> N >> M;

	vector < pair<ll, ll> > C(N);
	for (ll ii = 0; ii < N; ++ii){
		ll A, B;
		cin >> A >> B;
		C[ii] = make_pair(A, B);
	}
	sort(C.begin(), C.end());

	ll ans = 0;
	ll rem = M;
	for (ll ii = 0; ii < N; ++ii){
		ll hon = min(rem, C[ii].second);
		rem -= hon;
		ans += hon * C[ii].first;
		if (rem == 0){
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}
