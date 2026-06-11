#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long

const int maxn = 1e5 + 500;
ll dp[2][maxn]; //dp[0][i]表示正向走到i点获得的最大能量，dp[1][i]为反向...
ll g[2][maxn];  //g[0][i]表示正向走到i点回到x=0位置所拥有的能量，g[1][i]反之...
ll x[maxn], v[maxn];
ll n, c, sum;

int main()
{
	scanf("%lld %lld", &n, &c);
	for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &x[i], &v[i]);
    }

    //正向遍历
	for (int i = 1; i <= n; i++)
    {
		sum += v[i];
		dp[0][i] = max(dp[0][i - 1], sum - x[i]);
		g[0][i] = sum - 2 * x[i];
	}

	sum = 0;
	//反向遍历
	for (int i = n; i >= 1; i--)
    {
		sum += v[i];
		dp[1][i] = max(dp[1][i + 1], sum - (c - x[i]));
		g[1][i] = sum - 2 * (c - x[i]);
	}

	ll ans = max(dp[0][n], dp[1][1]);

	for (int i = 1; i <= n; i++)
    {
		ans = max(ans, g[0][i] + dp[1][i + 1]);
		ans = max(ans, g[1][i] + dp[0][i - 1]);
	}

	printf("%lld\n", ans);//若ans<0可以选择不走

	return 0;
}
