#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;
#define ll long long int
#define maxn 100005
#define mod 1e9+7

void _init() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int main() {
	_init();

	int h, w;
	cin >> h >> w;
	ll dp[h][w];
	char arr[h][w];
	for (int i = 0; i < h; i++) {
		cin >> arr[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i < w; i++) {
		if (arr[0][i] == '#')dp[0][i] = 0;
		else dp[0][i] = dp[0][i - 1];
	}

	for (int i = 1; i < h; ++i)
	{
		if (arr[i][0] == '#') dp[i][0] = 0;
		else dp[i][0] = dp[i - 1][0];
	}

	for (int i = 1; i < h; ++i)
	{
		for (int j = 1; j < w; ++j)
		{
			if (arr[i][j] == '#')
			{
				dp[i][j] = 0;
			} else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= (int)mod;
			}
		}
	}

	cout << dp[h - 1][w - 1] << endl;

	return 0;
}







