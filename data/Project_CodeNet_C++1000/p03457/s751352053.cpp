#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <tuple>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

int main() {
	int n; cin >> n;
	int t = 0, x = 0, y = 0, nt, nx, ny;
	rep(i, 0, n) {
		cin >> nt >> nx >> ny;
		int move = abs(x - nx) + abs(y - ny);
		int dt = nt - t;
		if (move > dt || (move + dt) % 2) {
			cout << "No" << endl;
			return 0;
		}
		t = nt;
		x = nx;
		y = ny;
	}
	cout << "Yes" << endl;
	return 0;
}