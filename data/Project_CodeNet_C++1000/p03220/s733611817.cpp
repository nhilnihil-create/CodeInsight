#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, t, a;
	cin >> n >> t >> a;
	double d = 0x3f3f3f3f;
	int res = -1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (abs(t - 0.006 * x - a) < d) {
			d = abs(t - 0.006 * x - a);
			res = i;
		}
	}
	cout << res << endl;
}
