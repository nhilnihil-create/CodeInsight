#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const double EPS = 1e-10;
typedef pair<int, int> P;
vector<int> v[200000];
int main() {
	int H, W, N;
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		r--; c--;
		v[c].push_back(r);
	}
	for (int i = 0; i < W; i++) {
		v[i].push_back(H);
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
	}
	int ans = 1 << 30;
	int sum = 0;
	int y = 0;
	for (int i = 0; i < W; i++) {
		int idx = upper_bound(v[i].begin(), v[i].end(), y) - v[i].begin();
		ans = min(ans, sum + (v[i][idx] - y));
		if (i == W - 1) break;
		bool ok = 0;
		while (y + 1 < v[i][idx]) {
			y++;
			sum++;
			int idx2 = lower_bound(v[i + 1].begin(), v[i + 1].end(), y) - v[i + 1].begin();
			if (v[i + 1][idx2] != y) {
				ok = 1;
				break;
			}
		}
		if (!ok) break;
	}
	cout << ans << endl;

}