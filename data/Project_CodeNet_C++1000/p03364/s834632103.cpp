#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
const int maxn = 600 + 10;
const int maxm = maxn * maxn;
char s[maxn][maxn];
ll f[maxn][maxn], sf[maxn][maxn], g[maxn][maxn], sg[maxn][maxn];
ll p[maxn * maxn];
bool ans[maxn][maxn];
int n;
void solve(const ll mod)
{
	ll b = std::uniform_int_distribution<>(0.25 * mod, 0.75 * mod)(gen);
	p[0] = 1; for(int i = 1; i < maxm; ++i) p[i] = p[i - 1] * b % mod;
	for(int i = 1; i <= (n << 1); ++i)
	{
		for(int j = 1; j <= (n << 1); ++j) 
			f[i][j] = (f[i][j - 1] * b + s[i][j] - 'a') % mod;
		for(int j = 1; j <= n; ++j)
			sf[i][j] = (f[i][j + n - 1] + mod - f[i][j - 1] * p[n] % mod) % mod;
	}
	for(int j = 1; j <= n; ++j)
	{
		for(int i = 1; i <= (n << 1); ++i)
			f[i][j] = (f[i - 1][j] * p[n] + sf[i][j]) % mod;
		for(int i = 1; i <= n; ++i)
			sf[i][j] = (f[i + n - 1][j] + mod - f[i - 1][j] * p[n * n] % mod) % mod;
	}
	for(int j = 1; j <= (n << 1); ++j)
	{
		for(int i = 1; i <= (n << 1); ++i)
			g[i][j] = (g[i - 1][j] * b + s[i][j] - 'a') % mod;
		for(int i = 1; i <= n; ++i)
			sg[i][j] = (g[i + n - 1][j] + mod - g[i - 1][j] * p[n] % mod) % mod;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= (n << 1); ++j) 
			g[i][j] = (g[i][j - 1] * p[n] + sg[i][j]) % mod;
		for(int j = 1; j <= n; ++j)
			sg[i][j] = (g[i][j + n - 1] + mod - g[i][j - 1] * p[n * n] % mod) % mod;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			//cout << i << ' ' << j << ' ' << sf[i][j] << ' ' << sg[i][j] << endl;
			if(sf[i][j] != sg[i][j])
				ans[i][j] = 0;
		}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= n; ++j)
		{
			ans[i][j] = 1;
			s[i + n][j] = s[i][j + n] = s[i + n][j + n] = s[i][j];
		}
	}
	solve(1e9 + 7);
	solve(1e9 + 7);
	int ret = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			ret += ans[i][j];
	printf("%d\n", ret);
	return 0;
}