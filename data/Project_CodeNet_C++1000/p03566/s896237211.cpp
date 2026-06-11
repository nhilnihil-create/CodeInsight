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

const int INF = 1e9 + 239;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	vector<int> t(n);
	vector<int> v(n);
	int st = 0;
	for (auto &x : t) {
		cin >> x;
		x *= 2;
		st += x;
	}
	for (auto &x : v) {
		cin >> x;
		x *= 2;
	}
	vector<int> mv(st + 1, INF);
	mv.front() = 0;
	mv.back() = 0;
	int p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = p; j <= p + t[i]; j++) {
			mv[j] = min(mv[j], v[i]);
		}
		p += t[i];
	}
	vector<int> lv = mv;
	vector<int> rv = mv;
	for (int i = 1; i <= p; i++) {
		lv[i] = min(lv[i], lv[i - 1] + 1);
	}
	for (int i = p - 1; i >= 0; i--) {
		rv[i] = min(rv[i], rv[i + 1] + 1);
	}
	int ans = 0;
	for (int i = 0; i < p; i++) {
		ans += min(lv[i], rv[i]) + min(lv[i + 1], rv[i + 1]);
	}
	double rs = (double)ans / 8;
	cout << fixed << setprecision(16);
	cout << rs << endl;
}
