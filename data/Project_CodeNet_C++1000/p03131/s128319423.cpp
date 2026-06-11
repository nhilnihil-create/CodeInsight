#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

signed main() {
	ll K, A, B; cin >> K >> A >> B;
	if (B - A <= 2)cout << K + 1 << endl;
	else {
		if (K <= A - 1)cout << K + 1 << endl;
		else {
			K -= A - 1;
			ll ans = A;
			ans += K / 2 * (B - A);
			if (K % 2 == 1)ans++;
			cout << ans << endl;
		}
	}
}