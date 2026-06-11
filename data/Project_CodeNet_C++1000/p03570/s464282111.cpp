#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 200005;

char s[MaxN + 5];
int dp[MaxN + 5];
int pre[MaxN + 4];
int best[1 << 26];

int main()
{
	while(scanf("%s", s + 1) != EOF)
	{
		int len = strlen(s + 1);
		for(int i = 1; i <= len; i++)
			pre[i] = pre[i - 1] ^ (1 << (s[i] - 'a'));
		for(int i = 1; i <= len; i++)
			dp[i] = inf;
		dp[0] = 0;
		for(int i = 1; i <= (1 << 26); i++)
			best[i] = inf;
		best[0] = 0;
		for(int i = 1; i <= len; i++) {
			dp[i] = min(dp[i], best[pre[i]] + 1);
			for(int j = 0; j < 26; j++) {
				int tmp = pre[i] ^ (1 << j);
				dp[i] = min(dp[i], best[tmp] + 1);
			}
			best[pre[i]] = min(best[pre[i]], dp[i]);
		}
		printf("%d\n", dp[len]);
	}
	return 0;
}