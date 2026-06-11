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


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)

int main() {
	ll H, W, D;

	cin >> H >> W >> D;

	map<int, pair<ll, ll> > m;

	ll a[H][W];
	rep(y, H) {
		rep(x, W) {
			cin >> a[y][x];
			m[a[y][x]] = mkp(y, x);
		}
	}


	vector<ll> imos(H * W + 1, 0);


	for(int i = D; i <= H * W; i++) {
			pair<int, int> cp = m[i - D];
			pair<int, int> np = m[i];		
			imos[i] = imos[i - D] + abs(cp.first - np.first) + abs(cp.second - np.second);	
	}

	int q;
	cin >> q;

	rep(i, q) {
		int L, R;
		cin >> L >> R;

		cout << imos[R] - imos[L] << endl;

	}

	return 0;
}