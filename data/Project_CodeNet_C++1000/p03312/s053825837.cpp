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
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 4e18;

void Search(int l, int r, int& x, vector<ll>& sum) {
	ll s = sum[r]+sum[l];
	int idx = lower_bound(sum.begin(), sum.end(), s / 2) - sum.begin();
	if (abs(s / 2 - sum[idx - 1]) < abs(s / 2 - sum[idx])) {
		x = idx - 1;
	}
	else x = idx;
}

int main() {
	int n; cin >> n;
	vector<ll> a(n),sum(n+1,0);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) {
		sum[i + 1] = sum[i] + a[i];
	}
	ll ans = INF;
	rep(i, 2, n-1) {
		int f; Search(0, i, f, sum);
		ll lmax = max(sum[i] - sum[f], sum[f] - sum[0]);
		ll lmin = min(sum[i] - sum[f], sum[f] - sum[0]);
		int g; Search(i, n, g, sum);
		ll rmax = max(sum[g] - sum[i], sum[n] - sum[g]);
		ll rmin = min(sum[g] - sum[i], sum[n] - sum[g]);
		ans = min(ans, max(lmax, rmax) - min(lmin, rmin));
	}
	cout << ans << endl;
	return 0;
}