#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[320][320][320];
int main()
{
	string x;
	cin >> x;
	int gen;
	scanf("%d", &gen);
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < x.size() - i; j++)
		{
			int s = j, t = j + i;
			for (int k = 0; k <= gen; k++)
			{
				if (s == t)dp[s][t][k] = 1;
				else
				{
					dp[s][t][k] = max(dp[s][t][k], dp[s + 1][t][k]);
					dp[s][t][k] = max(dp[s][t][k], dp[s][t - 1][k]);
					dp[s][t][k + (x[s] != x[t])] = max(dp[s][t][k + (x[s] != x[t])], dp[s + 1][t - 1][k] + 2);
				}
			}
		}
	}
	printf("%d\n", dp[0][x.size() - 1][gen]);
}
