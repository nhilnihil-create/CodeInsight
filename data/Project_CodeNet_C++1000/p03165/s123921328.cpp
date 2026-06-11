#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int dp[3001][3001];

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i+1][j+1] = dp[i][j] + 1;
			} else {
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}

	int length = dp[n][m];
	int l = n;
	int r = m;
	string ans = "";
	while (length > 0) {
		if (s[l-1] == t[r-1]) {
			ans += s[l-1];
			l--;
			r--;
			length--;
		} else if (dp[l][r] == dp[l-1][r]) l--;
		else r--;
	}
	reverse(ALL(ans));
	cout << ans << endl;
}