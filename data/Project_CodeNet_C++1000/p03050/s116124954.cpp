#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll N; cin >> N;
	ll ans = 0;
	for (ll i=1; i*i<N; i++) {
		if (N%i==0) {
			if (i>2 && N%(i-1)!=0 && N-(i-1)*(N/(i-1))==N/(i-1)) {
				// cout << i-1 << endl;
				ans += i-1ll;
			}
			ll j = N/i;
			if (N%j==0 && j>2 && N%(j-1)!=0 && N-(j-1)*(N/(j-1))==N/(j-1)) {
				// cout << j-1 << endl;
				ans += j-1ll;
			}
		}
	}
	cout << ans << endl;

	return 0;
}