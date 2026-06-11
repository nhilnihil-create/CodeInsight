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
	string a, b, c;
	cin >> n >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] == c[i]) {
			//
		} else if (a[i] == b[i] || a[i] == c[i] || b[i] == c[i]) {
			ans++;
		} else {
			ans += 2;
		}
	}
	cout << ans << '\n';
}
