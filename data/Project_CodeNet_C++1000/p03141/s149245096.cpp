
// C - Different Strokes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> P(N);

	for (int i=0; i<N; i++) {
		int A, B;
		cin >> A >> B;
		P[i] = make_pair(A, B);
	}

	sort(P.begin(), P.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return a.first + a.second > b.first + b.second;
	});

	// **** debug ****
	/*
	for (int i=0; i<N; i++) {
		cout << P[i].first << " " << P[i].second << endl;
	}
	*/

	ll ans = 0;

	for (int i=0; i<N; i++) {
		if (i % 2 == 0) ans += P[i].first;
		else ans -= P[i].second;
	}

	cout << ans << endl;

	return 0;
}