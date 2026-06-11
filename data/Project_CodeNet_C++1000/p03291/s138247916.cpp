#include <iostream>
#include <vector>
using namespace std;
#define myfill(a, val, type) fill((type *)a, (type *)a+sizeof(a)/sizeof(type), val)
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	string s;
	cin >> s;
	int len = s.size();
	long long dp[len+1][4]; myfill(dp, 0, long long);
	dp[0][0] = 1;
	for (int i = 0; i < len; i++) {
		for (char c : {'A', 'B', 'C'}) {
			if (s[i] != '?' && s[i] != c) continue;
			for (int x = 0; x < 4; x++) {
				dp[i+1][x] = mod(dp[i+1][x] + dp[i][x]);
			}
			int y = c - 'A';
			dp[i+1][y+1] = mod(dp[i+1][y+1] + dp[i][y]);
		}
	}
	long long ans = dp[len][3];
	cout << ans << endl;
	return 0;
}