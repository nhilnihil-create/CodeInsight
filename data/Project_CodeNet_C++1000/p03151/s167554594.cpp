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
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[i] += x;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[i] -= x;
	}
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += d[i];
	}
	int sum_neg = 0;
	int c_neg = 0;
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		if (d[i] >= 0) {
			pos.push_back(d[i]);
		} else {
			sum_neg += d[i];
			c_neg++;
		}
	}
	sort(pos.rbegin(), pos.rend());
	for (int i = 0; i <= (int)pos.size(); i++) {
		if (sum_neg >= 0) {
			cout << i + c_neg << '\n';
			return 0;
		}
		if (i < (int)pos.size()) sum_neg += pos[i];
	}
	cout << -1 << '\n';
}

