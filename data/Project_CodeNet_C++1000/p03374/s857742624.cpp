#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int n;
long long c;
vector <long long> x, v, sum, macs, dist;
const long long INF = 1e18;

int main() {
	cin >> n >> c;
	x = v = vector <long long> (n);
	rep (i, n) cin >> x[i] >> v[i];

	long long ans = 0;
	rep (cnt, 2) {
		dist = sum = macs = vector <long long> (n + 1, 0);
		long long tmpMax = -INF, tmpDist = 0;
		rep (i, n) {
			sum[i + 1] += sum[i] + v[i];
			if (tmpMax < sum[i + 1] - x[i]) {
				tmpMax = max(tmpMax, sum[i + 1] - x[i]);
				tmpDist = x[i];
			}
			dist[i + 1] = tmpDist;
			macs[i + 1] = tmpMax;
		}

		long long nowSum = 0;
		rep (i, n + 1) {
			if (!i) {
				ans = max(ans, macs[n]);
				continue;
			}
			nowSum += v[n - i];
			ans = max({ans,
					   nowSum - c + x[n - i],
					   nowSum + macs[n - i] - (c - x[n - i]) * 2});
		}

		reverse(v.begin(), v.end());
		reverse(x.begin(), x.end());
		for (auto& i: x) i = c - i;
	}
	cout << ans << endl;
	return 0;
}
