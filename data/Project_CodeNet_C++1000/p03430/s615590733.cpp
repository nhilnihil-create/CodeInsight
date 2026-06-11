#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e2 + 20;

int dp[maxn][maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int k;
	cin >> k;

	int n = s.size();

	for(int l = n - 1; l >= 0; l--)
		for(int r = l; r < n; r++)
			for(int i = 0; i <= k; i++)
			{
				if(l == r)
				{
					dp[l][r][i] = 1;
					continue;
				}

				if(r - l + 1 == 2)
				{
					dp[l][r][i] = 1;
					if(s[l] == s[r] || i)
						dp[l][r][i] = 2;
					continue;
				}

				if(i)
					dp[l][r][i] = max(dp[l][r][i] , dp[l + 1][r - 1][i - 1] + 2);
				if(s[l] == s[r])
					dp[l][r][i] = max(dp[l][r][i] , dp[l + 1][r - 1][i] + 2);

				dp[l][r][i] = max(dp[l][r][i] , max(dp[l + 1][r][i] , dp[l][r - 1][i]));
			}

	cout << dp[0][n - 1][k] << endl;
}




















