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
	int a, b;
	cin >> a >> b;
	vector<int> c(3);
	while (n--) {
		int x;
		cin >> x;
		if (x <= a) {
			c[0]++;
		} else if (a < x && x <= b) {
			c[1]++;
		} else {
			c[2]++;
		}
	}
	cout << *min_element(c.begin(), c.end()) << '\n';
}
