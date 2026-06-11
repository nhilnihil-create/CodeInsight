#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int K = 30;
const int INF = 1e9 + 239;

int solve(vector<int> a, vector<int> b, int L, int R) {
	if (L > R) {
		return 0;
	}
	sort(b.begin(), b.end());
	auto cnt = [&](int l, int r) {
		int cc = upper_bound(b.begin(), b.end(), r) - lower_bound(b.begin(), b.end(), l);
		return cc & 1;
	};
	int xr = 0;
	for (auto t : a) {
		xr ^= cnt(L - t, R - t);
	}
	return xr;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (auto &t : a) {
		cin >> t;
	}
	for (auto &t : b) {
		cin >> t;
	}
	int ans = 0;
	for (int bt = 0; bt < K; bt++) {
		vector<int> na = a;
		vector<int> nb = b;
		for (auto &t : na) {
			t %= (2 << bt);
		}
		for (auto &t : nb) {
			t %= (2 << bt);
		}
		int c = 0;
		c ^= solve(na, nb, (1 << bt), (2 << bt) - 1);
		c ^= solve(na, nb, (3 << bt), INF);
		if (c) ans |= 1 << bt;
	}
	cout << ans << endl;
}
