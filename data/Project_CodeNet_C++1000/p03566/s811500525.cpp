#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>

typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n;i>s;i--)
#define rep_re(i,s,n)for(ll i = n;i>=s;i--)
using namespace std;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll t[202];
double v[202];
double maxV[200001];
int main() {
	ll n, T = 0; cin >> n;
	repe(i, 1, n) cin >> t[i];
	repe(i, 1, n) cin >> v[i];

	repe(i, 1, n) {
		T += t[i];
	}

	rep(i, 0, 200001)maxV[i] = INF;

	ll nowT = 1;
	maxV[0] = 0;
	maxV[T * 2] = 0;

	repe(i, 1, n) {
		maxV[nowT - 1] = min(maxV[nowT - 1], v[i]);
		rep(ti, 0, t[i]) {
			ll t1 = nowT + ti * 2;
			ll t2 = nowT + ti * 2 + 1;
			maxV[t1] = min(maxV[t1], v[i]);
			maxV[t2] = min(maxV[t2], v[i]);
		}
		nowT += t[i] * 2;
		//maxV[nowT] = min(maxV[nowT], v[i]);
	}

	rep(ti, 0, 2 * T) {
		maxV[ti + 1] = min(maxV[ti + 1], maxV[ti] + 0.5);
	}
	rep_r(ti, 0, 2 * T) {
		maxV[ti] = min(maxV[ti], maxV[ti + 1] + 0.5);
	}
	double ans = 0;

	rep(i, 0, 2 * T) {
		ans += (maxV[i] + maxV[i + 1])*0.5 / 2;
	}

	printf("%.10f\n", ans);
	return 0;
}