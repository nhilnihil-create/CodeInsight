#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 5010;
const long long oo = 1e18;
int n, p[maxn], m;
long long A, B;
long long dp[maxn][maxn << 1], mx[maxn][maxn << 1];
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> A >> B;
	for(int i = 1; i <= n; i ++)
	{
		int a;
		cin >> a;
		p[a] = i * 2;
	}
	m = n * 2 + 1;
	for(int i = 1; i <= n; i ++)
	{
		mx[i][0] = oo;
		for(int j = 1; j <= m; j ++)
		{
			long long a;
			if(j % 2 == 0)
				a = mx[i - 1][j - 1];
			else
				a = mx[i - 1][j];
			if(j > p[i])
				a += A;
			else if(j < p[i])
				a += B;
			dp[i][j] = a;
			mx[i][j] = min(mx[i][j - 1], dp[i][j]);
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	cout << mx[n][m] << endl;
	return 0;
}
/*
5 1 9
3 5 1 4 2 
*/