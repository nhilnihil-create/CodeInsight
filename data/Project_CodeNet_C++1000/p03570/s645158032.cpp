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

int dpmin[1 << 26];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> cnt(26);
	fill(dpmin, dpmin + (1 << 26), INF);
	string s;
	cin >> s;
	int cm = 0;
	dpmin[cm] = 0;
	int n = (int)s.size();
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		char t = s[i];
		cm ^= (1 << (t - 'a'));
		int cdp = INF;
		cdp = dpmin[cm];
		for (int j = 0; j < 26; j++) {
			cdp = min(cdp, dpmin[cm ^ (1 << j)]);
		}
		cdp++;
		dpmin[cm] = min(dpmin[cm], cdp);
		dp[i] = cdp;
	}
	cout << dp[n - 1] << endl;
}
