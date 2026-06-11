#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> v(h, vector<int>(w));
	rep(i,h) rep(j,w) cin >> v[i][j];
	vector<pair<pii, pii>> ans;
	int k = 0;
	int li = h - 1;
	int lj = h % 2 == 0 ? 0: w - 1;
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < w; j++) {
				if (i == li && j == lj) continue;
				if (k == 0) {
					if (v[i][j] % 2 == 0) continue;
					else {
						int ni = j != w - 1? i: i + 1;
						int nj = j != w - 1? j + 1: j;
						ans.push_back(make_pair(make_pair(i, j), make_pair(ni, nj)));
						k = 1;
					}
				} else {
					if (v[i][j] % 2 == 1) k = 0;
					else {
						int ni = j != w - 1? i: i + 1;
						int nj = j != w - 1? j + 1: j;
						ans.push_back(make_pair(make_pair(i, j), make_pair(ni, nj)));
					}
				}
			}
		} else {
			for (int j = w - 1; j >= 0; j--) {
				if (i == li && j == lj) continue;
				if (k == 0) {
					if (v[i][j] % 2 == 0) continue;
					else {
						int ni = j != 0 ? i: i + 1;
						int nj = j != 0 ? j - 1: j;
						ans.push_back(make_pair(make_pair(i, j), make_pair(ni, nj)));
						k = 1;
					}
				} else {
					if (v[i][j] % 2 == 1) k = 0;
					else {
						int ni = j != 0 ? i: i + 1;
						int nj = j != 0 ? j - 1: j;
						ans.push_back(make_pair(make_pair(i, j), make_pair(ni, nj)));
					}
				}
			}
		}
	}
	int n = ans.size();
	cout << n << endl;
	rep(i,n) {
		cout << 1 + ans[i].first.first << " " << 1 + ans[i].first.second << " " << 1 + ans[i].second.first << " " <<	1 + ans[i].second.second << endl;
	}
}

int main() {
	solve();
	return 0;
}