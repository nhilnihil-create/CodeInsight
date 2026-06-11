#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> f(n);
	vector<vector<int>> p(n, vector<int>(11));
	rep(i, n) {
		int now = 0;
		rep(j, 10){
			int tmp;
			cin >> tmp;
			now += tmp<<j;
		}
		f[i] = now;
	}
	rep(i, n) rep(j, 11) {
		cin >> p[i][j];
	}
	int ans = -1001001001;
	for(int bit = 1; bit < (1<<10); bit++) {
		int now = 0;
		rep(i, n) {
			int same = 0;
			rep(j, 10) {
				if(((bit>>j) & 1) && ((f[i]>>j) & 1)) {
					same++;
				}
			}
			now += p[i][same];
		}
		ans = max(ans, now); 
	}
	cout << ans << endl;
	return 0;
}