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

	string s;
	cin >> s;
	int n = (int)s.size();
	int ans = n;
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] != s[i + 1]) {
			ans = min(ans, max(i + 1, n - (i + 1)));
		}
	}
	cout << ans << endl;
}
