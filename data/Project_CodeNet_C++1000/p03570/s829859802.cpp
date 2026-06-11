#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

int a[200003];
int dp[(1 << 26) + 3];

int main() {
	string s; cin >> s;
	a[0] = 0;
	for (int i = 1; i <= (int)s.length(); i++) {
		a[i] = 1 << (s[i - 1] - 'a');
		a[i] ^= a[i - 1];
	}
	for (int i = 0; i < (1 << 26); i++) dp[i] = 1e9;
	dp[0] = 0;
	int ans;
	for (int i = 1; i <= (int)s.length(); i++) {
		int t = dp[a[i]] + 1;
		for (int j = 0; j < 26; j++) {
			t = min(t, dp[a[i] ^ (1 << j)] + 1);
		}
		dp[a[i]] = min(dp[a[i]], t);
		ans = t;
	}
	cout << ans << endl;
	return 0;
}