#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define case(i) cout<<"Case #"<<i<<": "
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pr;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;


int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, 0, n) cin >> a[i] >> b[i];
	ll ans = 0;
	rep(i, 0, n) {
		if ((k & a[i]) == a[i]) ans += b[i];
	}
	rep(i, 0, 31) {
		int j = 30 - i;
		if ((k >> j) & 1) {
			int l = k - (1 << j);
			l |= (1 << j) - 1;
			ll sub = 0;
			rep(i, 0, n) {
				if ((l & a[i]) == a[i]) sub += b[i];
			}
			ans = max(ans, sub);
		}
	}
	cout << ans << endl;
	return 0;
}
