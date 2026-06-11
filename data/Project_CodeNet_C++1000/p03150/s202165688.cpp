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

const string need = "keyence";

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i <= (int)need.size(); i++) {
		if (s.substr(0, i) == need.substr(0, i) && s.substr(n - (int)need.size() + i, (int)need.size() - i) == need.substr(i, (int)need.size() - i)) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}

