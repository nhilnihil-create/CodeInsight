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
	ll n,m;
	cin >> n >> m;

	ll max_v = 1;
	for (ll i = 1; i * i <= m; i++) {
		if (m % i == 0) {
			if (m / i >= n) {
				max_v = max(i, max_v);
			}
			if (i >= n) {
				max_v = max(m / i, max_v);
			}
		}
	}
	cout << max_v << endl;

	return 0;
}
