
// C - Flip,Flip, and Flip......

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N, M;
	cin >> N >> M;

	ll ans;

	if (N == 1 && M == 1) {
		ans = 1;
	} else if (N == 1) {
		ans = M - 2;
	} else if (M == 1) {
		ans = N - 2;
	} else {
		ans = (N - 2) * (M - 2);
	}

	cout << ans << endl;

	return 0;
}