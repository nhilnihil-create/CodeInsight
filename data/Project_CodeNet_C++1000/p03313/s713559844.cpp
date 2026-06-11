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

#define int long long

const int N = 18;
const int INF = 1e18 + 239;

pair<int, int> conq(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) swap(a, b);
	return make_pair(a.first, max(a.second, b.first));
}

int a[1 << N];
pair<int, int> mn[1 << N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		cin >> a[i];
		mn[i] = {a[i], -INF};
	}
	for (int i = 0; i < n; i++) {
		for (int j = (1 << n) - 1; j >= 0; j--) {
			if ((j >> i) & 1) {
				mn[j] = conq(mn[j], mn[j ^ (1 << i)]);
			}
		}
	}
	int c = 0;
	for (int i = 0; i < (1 << n); i++) {
		c = max(c, mn[i].first + mn[i].second);
		if (i > 0) cout << c << '\n';
	}
}
