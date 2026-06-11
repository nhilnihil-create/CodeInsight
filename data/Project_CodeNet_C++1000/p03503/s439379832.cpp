#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int f[105][10];
	rep(i, n) {
		rep(j, 10) {
			cin >> f[i][j];
		}
	}
	vector<vector<int>> P(n, vector<int>(11));
	rep(i, n)rep(j, 11) cin >> P[i][j];
	int ans = -inf;
	rep(bit, (1 << 10)) {
		vector<int> rec(n);
		int cnt = 0;
		rep(i, 10) if (bit & (1 << i)) cnt++;
		if (cnt == 0) continue;
		rep(i, n) {
			rep(j, 10) if (bit & (1 << j) && f[i][j]) rec[i]++;
		}
		int tmp = 0;
		rep(i, n) {
			tmp += P[i][rec[i]];
		}
		maxs(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
