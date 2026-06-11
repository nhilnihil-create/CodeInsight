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
	for (auto &t : a) {
		cin >> t;
	}
	reverse(a.begin(), a.end());
	int l = 2;
	int r = 2;
	for (auto t : a) {
		int up = (r / t) * t;
		if (l <= up) {
			//
		} else {
			cout << -1 << endl;
			return 0;
		}
		int nl = ((l + t - 1) / t) * t;
		int nr = up + t - 1;
		l = nl;
		r = nr;
	}
	cout << l << ' ' << r << endl;
}