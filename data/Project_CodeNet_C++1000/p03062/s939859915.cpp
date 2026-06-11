#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans, cnt;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> A(N);
	rep(i, N) {
		int a;
		cin >> a;
		if (a < 0) cnt++;
		A[i] = abs(a);
		ans += A[i];
	}

	sort(A.begin(), A.end());

	if (cnt % 2 == 0) {
		cout << ans << endl;
	}
	else {
		cout << ans - (2 * A[0]) << endl;
	}

	return 0;
}