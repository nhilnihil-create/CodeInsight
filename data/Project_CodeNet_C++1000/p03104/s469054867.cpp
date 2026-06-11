#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll f(ll n) {
	if(n <= 0) return 0;
	ll res = (n%4 == 1 || n%4 == 2);
	ll cnt = 1;
	while (cnt+1 <= n) {
		cnt <<= 1;
		int now;
		if(n%(cnt<<1) < cnt) now = 0;
		else {
			now = (n%2 == 0);
		}
		res += now * cnt;
		// cout << cnt << " " << now << endl;
	}
	return res;
}

int main() {
	ll a, b;
	cin >> a >> b;
	if(a < b) swap(a, b);
	ll fa = f(a);
	ll fb = f(b-1);
	ll ans = fa ^ fb;
	cout << ans << endl;
	return 0;
}