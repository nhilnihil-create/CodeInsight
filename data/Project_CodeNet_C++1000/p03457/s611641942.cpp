#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = j; i < n; ++i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;



int main() {
	int n; cin >> n;

	int t = 0, x = 0, y = 0, tt, tx, ty;
	rep(i, 0, n) {
		cin >> tt >> tx >> ty;
		int diff = abs(tx - x) + abs(ty - y);
		if (tt - t < diff || (tt - t) % 2 != diff % 2) {
			cout << "No";
			return 0;
		}
		t = tt;
		x = tx;
		y = ty;
	}
	cout << "Yes";

	return 0;
}