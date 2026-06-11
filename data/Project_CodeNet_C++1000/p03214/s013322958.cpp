#pragma GCC optimize("O3", "unroll-loops")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

signed main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		int ai; cin >> ai;
		a[i] = ai * n;
	}
	int avr = accumulate(a.begin(), a.end(), 0) / n;
	vector<int> dis(n);
	for (int i = 0; i < n; ++i)
		dis[i] = abs(a[i] - avr);
	int mn = 10000000;
	for (int i = 0; i < n; ++i)
		mn = min(mn, dis[i]);
	for (int i = 0; i < n; ++i) {
		if (dis[i] == mn) {
			cout << (i) << endl;
			exit(0);
		}
	}
	return 0;
}