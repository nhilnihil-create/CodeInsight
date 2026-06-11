#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long ll;


int main() {
	int n; cin >> n;
	vector<ll> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	vector<ll> cand;
	ll ans = 2e18;
	for (int t = 2; t <= n - 2; t++) {
		cand.clear();
		ll tg = s[t] / 2;
		int lo = 1, hi = t - 1;
		while (hi - lo > 1) {
			int mid = lo + (hi - lo) / 2;
			if (s[mid] > tg) hi = mid;
			else lo = mid;
		}
		if (abs(s[t] - 2 * s[lo]) < abs(s[t] - 2 * s[hi])) {
			cand.push_back(s[lo]);
			cand.push_back(s[t] - s[lo]);
		}
		else {
			cand.push_back(s[hi]);
			cand.push_back(s[t] - s[hi]);
		}

		tg = (s[n] - s[t]) / 2;
		lo = t + 1, hi = n - 1;
		while (hi - lo > 1) {
			int mid = lo + (hi - lo) / 2;
			if (s[mid] - s[t] > tg) hi = mid;
			else lo = mid;
		}
		if (abs(s[n] - 2 * s[lo] + s[t]) < abs(s[n] - 2 * s[hi] + s[t])) {
			cand.push_back(s[n] - s[lo]);
			cand.push_back(s[lo] - s[t]);
		}
		else {
			cand.push_back(s[n] - s[hi]);
			cand.push_back(s[hi] - s[t]);
		}
		sort(cand.begin(), cand.end());
		ans = min(ans, cand[3] - cand[0]);
	}
	cout << ans << endl;
	return 0;
}
