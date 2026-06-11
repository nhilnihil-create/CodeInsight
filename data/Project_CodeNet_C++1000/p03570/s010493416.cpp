#include <bits/stdc++.h>
using namespace std;

int dp[1 << 26];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < (1 << 26); i++) {
		dp[i] = s.size();
	}
	int X = 0;
	dp[0] = 0;
	for (auto c : s) {
		int b = c - 'a';
		X ^= 1 << b;
		int nv = dp[X] + 1;
		for (int i = 0; i < 26; i++) {
			nv = min(nv, dp[X ^ (1 << i)] + 1);
		}
		dp[X] = min(dp[X], nv);
	}
	cout << max(dp[X], 1) << endl;
	return 0;
}
