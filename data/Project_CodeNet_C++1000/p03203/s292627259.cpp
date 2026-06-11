#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> c[MAXN];

int start[MAXN];

int main() {

	int h, w, n;
	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		c[y].push_back(x);
	}

	for (int i = 1; i <= w; i++) {
		sort(c[i].begin(), c[i].end());
	}

	int ans = h;

	for (int i = 1; i <= w; i++) {
		start[i] = start[i-1] + 1;
		for (int r : c[i]) {
			if (r == start[i]) {
				start[i]++;
			} else if (r > start[i]) {
				ans = min(ans, r - 1);
				break;
			}
		}

		// cout << i << " " << start[i] << endl;
	}

	cout << ans << endl;

	return 0;
}