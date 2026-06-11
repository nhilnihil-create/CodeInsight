#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 3003, M = N << 1;

char s[N], t[N];
int dp[N][N];

int main()
{
	//File("");
	scanf("%s", s + 1); scanf("%s", t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; i+=1)
		for (int j = 1; j <= m; j+=1)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	int now = dp[n][m], x = n, y = m;
	string ans = "";
	while (now > 0)
	{
		if (s[x] == t[y])
		{
			--now;
			ans = s[x] + ans;
			--x, --y;
		}
		else if (dp[x][y] == dp[x][y - 1]) --y;
		else --x;
	}
	cout << ans << endl;
	return 0;
}
