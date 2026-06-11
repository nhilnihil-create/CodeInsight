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

const vector<int> need = {1, 4, 7, 9};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(4);
	for (auto &t : v) {
		cin >> t;
	}
	sort(v.begin(), v.end());
	if (v == need) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

