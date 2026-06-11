#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);

	rep(i, n) {
		cin >> h[i];
	}

	sort(h.begin(), h.end());

	int diff = inf;

	for(int i = 0; i < n - k + 1; i++) {
		int cur_diff = h[i + k - 1] - h[i];
		if (cur_diff < diff) {
			diff = cur_diff;
		}
	}
	cout << diff << endl;
	return 0;
}
