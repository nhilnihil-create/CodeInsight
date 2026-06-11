#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, INF = 1e9;
int mask[N];
char s[N];
unordered_map<int, int> dp;
int &f(int x) {
	if (!dp.count(x)) dp[x] = INF;
	return dp[x];
}
int main() {
	scanf("%s", s);
	int n = (int) strlen(s);
	int ma = 0;
	for (int i = 0; i < n; ++ i) {
		ma ^= (1 << (s[i] - 'a'));
		mask[i] = ma;
	}
	f(0) = 0;
	int las = n;
	for (int i = 0; i < n; ++ i) {
		int ma = mask[i], dp = i + 1;
		dp = min(dp, f(ma) + 1);
		for (int j = 0; j < 26; ++ j) {
			int ma = mask[i] ^ (1 << j);
			dp = min(dp, f(ma) + 1);
		}
		las = dp;
		f(ma) = min(f(ma), dp);
	}
	printf("%d\n", las);
}
