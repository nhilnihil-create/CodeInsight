#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int dp[1 << 10], lst[105][11], ls[105][11];

int main()
{
	PRE;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 10;j++)cin >> lst[i][j];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= 10;j++)cin >> ls[i][j];
	}
	ll ans = -1e9 - 5;
	for (int i = 1;i < 1 << 10;i++)
	{
		ll t = 0;
		for (int k = 1;k <= n;k++)
		{
			int g = 0;
			for (int j = 1;j <= 10;j++)
			{
				if (i & (1 << (j - 1)) && lst[k][j])g++;
			}
			t += ls[k][g];
		}
		ans = max(t, ans);
	}
	cout << ans;
}