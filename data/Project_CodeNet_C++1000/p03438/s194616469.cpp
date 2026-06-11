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
	int sa = 0;
	int sb = 0;
	for (auto &t : a) {
		cin >> t;
		sa += t;
	}
	for (auto &t : b) {
		cin >> t;
		sb += t;
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= b[i]) {
			c += (b[i] - a[i] + 1) / 2;
		}
	}
	if (c <= sb - sa) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}
