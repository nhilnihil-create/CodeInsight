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
	int ans = 0;
	//x < m
	//x * m + x == n
	//x * (m + 1) == n
	auto relax_x = [&](int x) {
		int m = n / x  - 1;
		if (x < m) {
			ans += m;
		}
	};
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			relax_x(i);
			if (i * i < n) relax_x(n / i);
		}
	}
	cout << ans << endl;
}

