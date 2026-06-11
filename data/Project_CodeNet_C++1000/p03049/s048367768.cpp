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

	int n;
	cin >> n;
	int cA = 0;
	int cB = 0;
	int cBoth = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cA += (s.back() == 'A');
		cB += (s.front() == 'B');
		if (s.back() == 'A' && s.front() == 'B') {
			cBoth++;
			cA--;
			cB--;
		}
		for (int j = 0; j + 1 < (int)s.size(); j++) {
			ans += (s[j] == 'A' && s[j + 1] == 'B');
		} 
	}
	// cerr << ans << endl;
	// cerr << cA << ' ' << cB << ' ' << cBoth << endl;
	if (abs(cA - cB) < cBoth) {
		if (max(cA, cB) > 0) {
			cout << ans + max(cA, cB) + (cBoth - abs(cA - cB)) << '\n';
		} else {
			cout << ans + cBoth - 1 << '\n';
		}
	} else {
		cout << ans + min(cA, cB) + cBoth << '\n';
	}
}

