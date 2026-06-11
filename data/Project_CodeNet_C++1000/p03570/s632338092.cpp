#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int dp[1010101];

int main(void) {
	int cur = 0, i = 0;
	dp[0] = 0; mp[0] = 0;
	for (char c = getchar(); c >= 'a' && c <= 'z'; c = getchar()) {
		++i; cur ^= (1 << c - 'a');
		int cnt = __builtin_popcount(cur);
		dp[i] = 1 << 30;
		if (mp.count(cur))
			dp[i] = min(dp[i], dp[mp[cur]] + 1);
		for (int sigma = 0; sigma < 26; sigma++)
			if (mp.count(cur ^ (1 << sigma)))
				dp[i] = min(dp[i], dp[mp[cur ^ (1 << sigma)]] + 1);
		if (!mp.count(cur) || dp[mp[cur]] > dp[i])
			mp[cur] = i;
	}
	cout << dp[i] << endl;
	return 0;
}
