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



int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	int ans = 0;
	rep(i, 1, 30) {
		int t = 1 << i;
		vector<int> c=a;
		rep(j, 0, n) c[j]%= t;
		sort(c.begin(), c.end());
		int cnt = 0;
		rep(j,0,n){
			int d = b[j] % t;
			cnt += lower_bound(c.begin(), c.end(), 2 * t/2 - d)-c.begin();
			cnt += lower_bound(c.begin(), c.end(), 4 * t/2 - d) - c.begin();
			cnt -= lower_bound(c.begin(), c.end(), 1 * t/2 - d) - c.begin();
			cnt -= lower_bound(c.begin(), c.end(), 3 * t/2 - d) - c.begin();
		}
		if (cnt % 2) {
			ans += t/2;
		}
	}
	cout << ans << endl;
	return 0;
}