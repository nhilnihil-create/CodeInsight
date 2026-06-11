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

const int INF = 1e18 + 239;

struct Frac {
	int up;
	int dw;

	Frac() {
		up = INF;
		dw = 1;
	}

	Frac(int a, int b) {
		up = a;
		dw = b;
	}
	
	bool operator<(const Frac &other) {
		return up * other.dw < other.up * dw;
	}

	bool operator<=(const Frac &other) {
		return up * other.dw <= other.up * dw;
	}
};

Frac get(int a) {
	int s = 0;
	int ta = a;
	while (a > 0) {
		s += (a % 10);
		a /= 10;
	}
	return Frac(ta, s);
}

int next(int c) {
	c++;
 	Frac best = get(c);
 	int ans = c;
 	auto relax = [&](int n) {
 		if (get(n) < best) {
 			best = get(n);
 			ans = n;
 		}
 	};
 	relax(c + 1);
 	string kek = to_string(c);
 	for (int i = (int)kek.size() - 1; i >= 0; i--) {
 		kek[i] = '9';
 		relax(stoll(kek));
 	}
 	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// int n;
	// cin >> n;
	// Frac mn;
	// vector<int> ans;
	// for (int i = n; i > 0; i--) {
	// 	if (get(i) <= mn) {
	// 		ans.push_back(i);
	// 		mn = get(i);
	// 	}
	// }
	// reverse(ans.begin(), ans.end());
	// for (auto t : ans) {
	// 	cout << t << '\n';
	// }
	int k;
	cin >> k;
	int c = 1;
	while (k--) {
		cout << c << '\n';
		c = next(c);
	}
}
