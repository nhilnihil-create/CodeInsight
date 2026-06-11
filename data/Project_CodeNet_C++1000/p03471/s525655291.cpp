#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);


	int n, y;
	cin >> n >> y;
	rep(i, 0, n + 1) {
		rep(j, 0, n - i + 1) {
			if (y - 10000 * i - 5000 * j == 1000 * (n - i - j)) {
				cout << i << " " << j << " " << n - i - j << endl;
				return 0;
			}
		}
	}
	
	cout << "-1 -1 -1" << endl;
	return 0;
}