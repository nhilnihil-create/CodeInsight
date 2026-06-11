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

const int INF = 0x3f3f3f3f, N = 1003, M = N << 1, mod = 1000000007;

int n, m;
int dp[N][N];
char a[N][N];

int main()
{
	//File("");
	n = gi <int> (), m = gi <int> ();
	for (int i = 1; i <= n; i+=1) scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; i+=1) if (a[i][1] != '#') dp[i][1] = 1; else break;
	for (int i = 1; i <= m; i+=1) if (a[1][i] != '#') dp[1][i] = 1; else break;
	for (int i = 2; i <= n; i+=1)
		for (int j = 2; j <= m; j+=1)
			if (a[i][j] != '#')
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
	printf("%d\n", dp[n][m]);
	return 0;
}
