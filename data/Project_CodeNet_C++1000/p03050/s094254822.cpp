#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll ans = 0;
	if (n == 1) {
		dunk(0);
		return 0;
	}
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0 && i != 1) {
			if (ll(n / (i - 1)) == n % (i - 1)) ans += i - 1;
			if (i * i != n) {
				ll a = n / i;
				if (ll(n / (a - 1)) == n % (a - 1)) ans += a - 1;
			}
		}
		if (i == 1) {
			ll a = n / i;
			if (ll(n / (a - 1)) == n % (a - 1)) ans += a - 1;
		}
	}
	dunk(ans);
	return 0;
}
