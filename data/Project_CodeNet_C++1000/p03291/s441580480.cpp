#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = (ull)1e9 + 7;

int main(void)
{
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
	dp[0][0] = 1;
	rep(i, n) {
		char c = s[i];
		if (c == '?') {
			rep(j, 4) {
				(dp[i + 1][j] += dp[i][j] * 3) %= mod;
			}
			rep(j, 3) {
				(dp[i + 1][j + 1] += dp[i][j]) %= mod;
			}
		}
		else {
			rep(j, 4) {
				(dp[i + 1][j] += dp[i][j]) %= mod;
			}
			if (c == 'A') {
				(dp[i + 1][1] += dp[i][0]) %= mod;
			}
			if (c == 'B') {
				(dp[i + 1][2] += dp[i][1]) %= mod;
			}
			if (c == 'C') {
				(dp[i + 1][3] += dp[i][2]) %= mod;
			}
		}
	}
	cout << dp[n][3] << endl;
	return 0;
}
