#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;

int n;
unsigned long long x[200003], c;
unsigned long long sum[200003];

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + x[i];
	unsigned long long ans = 2e18;
	for (unsigned long long t = 1; t <= n; t++) {
		unsigned long long s = c*(t + n);
		for (int i = n; i > 0; i -= t) {
			unsigned long long k = (n - i + t) / t;
			if (k == 1) s += 5 * (sum[i] - sum[i > t ? i - t : 0]);
			else s +=(2*k + 1)*(sum[i] - sum[i > t ? i - t : 0]);
		}
		ans = min(ans, s);
	}
	cout << ans << endl;
	return 0;
}
