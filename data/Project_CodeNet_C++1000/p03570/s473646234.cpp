#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20], pd[1 << 26], state[1 << 20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) s[i] -= 'a';
	for (int i = 0; i < s.length(); i++) {
		if (i) state[i] = state[i - 1];
		state[i] ^= (1 << s[i]);
	}
	for (int i = 0; i < 1 << 26; i++) pd[i] = 1 << 20;
	pd[0] = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			dp[i] = 1;
			pd[state[i]] = 1;
			continue;
		}
		int now = state[i - 1];
		dp[i] = min(pd[now], pd[now ^ (1 << s[i])]) + 1;
		for (int j = 0; j < 26; j++) dp[i] = min(dp[i], pd[now ^ (1 << s[i]) ^ (1 << j)] + 1);
		pd[state[i]] = min(dp[i], pd[state[i]]);
	}
	cout << dp[s.length() - 1] << endl;
	return 0;
}

