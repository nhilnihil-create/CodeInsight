#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 100, maxm = 1 << 26, INF = 0x3f3f3f3f;
int dp[maxm + 5];
char s[maxn];
inline int idx(char c){return c - 'a';}
int main()
{
	scanf("%s", &s);
	int len = strlen(s);
	memset(dp, INF, sizeof dp); dp[0] = 0;
	int tmp = 0;
	for(int i = 0; i < len; ++i)
	{
		tmp ^= (1 << idx(s[i]));
		for(int j = 0; j < 26; ++j) dp[tmp] = min(dp[tmp], dp[tmp^(1 << j)] + 1);
	}
	printf("%d\n", max(1, dp[tmp]));
	return 0;
}