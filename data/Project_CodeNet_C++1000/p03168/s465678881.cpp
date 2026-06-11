#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<iomanip>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const ll INF = 1000000007;
double dp[3005][3005];

int main() {
	int n;
	cin >> n;
	vector<double>p(n);
	rep(i, n)cin >> p[i];
	rep(i, n) {
		rep(j, i + 2) {
			if (i == 0) {
				dp[i][0] = 1 - p[i];
				dp[i][1] = p[i];
				continue;
			}
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] * (1 - p[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
				//cout << dp[i][j] << endl;
			}
		}
	}
	double ans(0);
	rep(i, n + 1) {
		if (i > (n / 2)) {
			ans += dp[n - 1][i];
		}
	}
	cout <<setprecision(10)<< ans;
	return 0;
}