#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
const int INF = 1e9 + 1e8;

char str[N];
int dp[1 << 26];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str;
	int len = strlen(str);
	
	for (int s = 0; s < (1 << 26); s++) dp[s] = INF;
	int cur = 0;
	dp[0] = 0;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		cur ^= 1 << str[i] - 'a';
		int ret = INF;
		ret = min(ret, dp[cur] + 1);
		for (int j = 0; j < 26; j++) ret = min(ret, dp[cur ^ (1 << j)] + 1);
		dp[cur] = min(dp[cur], ret);
		ans = ret;
	}
	cout << ans << "\n";
	
	return 0;
}
