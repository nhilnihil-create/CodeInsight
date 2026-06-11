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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return a[i] + b[i] > a[j] + b[j];
	});
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			ans -= b[ind[i]];
		} else {
			ans += a[ind[i]];
		}
	}
	cout << ans << '\n';
}
