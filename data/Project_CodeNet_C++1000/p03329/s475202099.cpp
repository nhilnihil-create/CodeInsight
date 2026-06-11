#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int d[12] = {1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049};

int dp[13][100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = INF;
	}

	dp[0][0] = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j <= n; j++) {
			if (j - d[i] >= 0) {
				dp[i+1][j] = min(dp[i][j], dp[i+1][j - d[i]] + 1);
			} else {
				dp[i+1][j] = dp[i][j];
			}
		}
	}
	cout << dp[12][n] << endl;
}