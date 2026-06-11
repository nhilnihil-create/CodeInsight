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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n, k;
	cin >> n >> k;
	if (k >= (1 << n)) {
		cout << -1 << endl;
		return 0;
	}
	if (n == 1) {
		if (k == 0) {
			cout << "0 0 1 1" << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		vector<int> ans = {0};
		for (int i = 1; i < (1 << n); i++) {
			ans.push_back(i);
		}
		ans.push_back(0);
		for (int i = (1 << n) - 1; i > 0; i--) {
			ans.push_back(i);
		}
		for (auto t : ans) {
			cout << (t ^ k) << ' ';
		}
		cout << endl;
	}
}
