#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[1 << 26];
int main()
{
	string s;
	cin >> s;
	int now = 0;
	fill(dp, dp + (1 << 26), 1000000000);
	dp[0] = 0;
	for (int i = 0; i < s.size(); i++)
	{
		now ^= (1 << (s[i] - 'a'));
		for (int j = 0; j < 26; j++)dp[now] = min(dp[now], dp[now ^ (1 << j)] + 1);
	}
	printf("%d\n", max(1, dp[now]));
}