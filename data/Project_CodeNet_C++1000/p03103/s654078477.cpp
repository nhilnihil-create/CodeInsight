
// C - Energy Drink Collector

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

pair<ll, ll> P[100000];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<N; i++) {
		ll A, B;
		cin >> A >> B;
		P[i] = make_pair(A, B);
	}

	sort(P, P+N);

	ll ans = 0;
	ll m = 0;
	for (int i=0; i<N; i++) {
		ll A = P[i].first;
		ll B = P[i].second;
		if (m + B < M) {
			ans += A*B;
			m += B;
		} else {
			while (m < M) {
				ans += A;
				m += 1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}