#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, c;
	cin >> n >> c;
	vector<vector<int>> d(c, vector<int>(c)), col(n, vector<int>(n));
	rep(i, c) rep(j, c) cin >> d[i][j];
	rep(i, n) rep(j, n) {
		cin >> col[i][j];
		col[i][j]--;
	}
	vector<int> mod0(c), mod1(c), mod2(c);
	rep(nextc, c) {
		rep(i, n) {
			rep(j, n) {
				int nowc = col[i][j];
				if((i+j) % 3 == 0) {
					mod0[nextc] += d[nowc][nextc];
				} else if((i+j) % 3 == 1) {
					mod1[nextc] += d[nowc][nextc];
				} else {
					mod2[nextc] += d[nowc][nextc];
				}
			}
		}
	}
	int ans = 1001001001;
	for(int c0 = 0; c0 < c; c0++) {
		for(int c1 = 0; c1 < c; c1++) {
			for(int c2 = 0; c2 < c; c2++) {
				if(c0 == c1 || c1 == c2 || c2 == c0) continue;
				int now = mod0[c0] + mod1[c1] + mod2[c2];
				ans = min(ans, now);
			}
		}
	}
	cout << ans << endl;
	return 0;
}