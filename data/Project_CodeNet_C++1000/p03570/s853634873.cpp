#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

char s[MAXN];
int dp[1 << 26];

void load() {
	scanf("%s", s);
}

int solve() {
	memset(dp, INF, sizeof dp);
	dp[0] = 0;
	int pref = 0;
	for (int i = 0; s[i]; i++) {
		pref ^= 1 << s[i] - 'a';
		int tmp = dp[pref];
		for (int j = 0; j < 26; j++)
			tmp = min(tmp, dp[pref ^ 1 << j]);
		dp[pref] = min(dp[pref], tmp + 1);
	}
	return max(dp[pref], 1);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}