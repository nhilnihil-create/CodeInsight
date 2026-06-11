#define rep(i,a,b) for (int i = (a); i < (b); i++)
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
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;



int main() {
	int n; cin >> n;
	vector<int> t(n), v(n);
	rep(i, 0, n) cin >> t[i];
	rep(i, 0, n) cin >> v[i];
	vector<double> dp(110, -1e9);
	dp[0] = 0;
	rep(i, 0, n) rep(j, 0, t[i]) {
		vector<double> sub(110, -1e9);
		rep(k, 0, v[i] + 1) {
			sub[k] = max(sub[k], dp[k] + k);
			if (k < v[i]) {
				sub[k] = max(sub[k], dp[k] + k + 0.25);
				sub[k + 1] = max(sub[k + 1], dp[k] + k + 0.5);
			}
			if (k > 0) sub[k - 1] = max(sub[k - 1], dp[k] + k - 0.5);
		}
		swap(dp, sub);
	}
	cout.precision(10);
	cout << fixed << dp[0] << endl;
	return 0;
}