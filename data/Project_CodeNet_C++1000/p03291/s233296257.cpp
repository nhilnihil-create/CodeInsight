#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
#define MAX_N (100010)

int main()
{
	char S[MAX_N];
	scanf("%s", S);
	int N = strlen(S);

	ll dp[MAX_N][4];
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 4; j++)
			dp[i][j] = dp[i - 1][j];

		switch (S[i - 1]) {
		case 'A':
			dp[i][1] += dp[i - 1][0];
			break;
		case 'B':
			dp[i][2] += dp[i - 1][1];
			break;
		case 'C':
			dp[i][3] += dp[i - 1][2];
			break;
		case '?':
			for(int j = 1; j < 4; j++)
				dp[i][j] += dp[i - 1][j - 1];
			for(int j = 0; j < 4; j++)
				dp[i][j] += dp[i - 1][j] * 2LL;
			break;
		}
		for(int j = 0; j < 4; j++)
			dp[i][j] %= MOD;
	}
	printf("%lld\n", dp[N][3]);

	return 0;
}
