#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8] = { +1, +1, +1, 0, 0, -1, -1, -1};
int YY[8] = { +1, 0, -1, +1, -1, +1, 0, -1};
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int dp[3001][3001];
int n;
string s;

void solve() {
	dp[n][0] = (s[n - 2] == '>') ? 1 : 0;
	dp[n][1] = (s[n - 2] == '<') ? 1 : 0;
	for (int i = n - 1; i >= 2; i--) {
		int total = n - i + 1;
		for (int g = 0; g <= total; g++) {
			if (g == 0) {
				if (i == n)continue;
				dp[i][g] = 0;
				if (s[i - 2] == '<') continue;
				for (int j = 1; j <= total; j++) {
					dp[i][g] = (dp[i][g] + dp[i + 1][total - j]) % mod;
				}
			} else {
				if (s[i - 2] == '>') {
					dp[i][g] = (mod + dp[i][g - 1] - dp[i + 1][g - 1]) % mod;
				} else {
					dp[i][g] = (dp[i][g - 1] + dp[i + 1][g - 1]) % mod;
				}
			}
		}
	}
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;
	cin >> s;

	solve();

	int ans = 0;

	for (int g = n - 1; g >= 0; g--) {
		ans = ans + dp[2][g];
		if (ans >= mod)ans -= mod;
	}

	cout << ans << endl;

	return 0;
}