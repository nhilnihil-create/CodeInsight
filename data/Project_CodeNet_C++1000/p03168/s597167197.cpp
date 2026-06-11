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

int n;
double dp[N][N], p[N];

int main()
{
	//File("");
	n = gi <int> ();
	for (int i = 1; i <= n; i+=1) scanf("%lf", &p[i]);
	dp[1][0] = 1 - p[1], dp[1][1] = p[1];
	for (int i = 2; i <= n; i+=1)
		for (int j = 0; j <= i; j+=1)
			dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
	double ans = 0;
	for (int i = n; i >= (n + 1) / 2; i-=1) ans += dp[n][i];
	printf("%.10lf\n", ans);
	return 0;
}
