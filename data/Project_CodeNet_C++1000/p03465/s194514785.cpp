#include<bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long
#define fi first
#define se second
#define maxn 2001
 
const int mod = 1e9+7 ;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
 
bool dp[maxn][100001];
int pre[maxn];
 
signed main()
{
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	fastio;
	int n;	cin >> n;
	int a[n+1], sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100000; j++)
		{
			if (!dp[i][j])
			{
				if (j >= a[i])
				{
					if (j + a[i] <= 100000)
					dp[i][j] = max(dp[i-1][j-a[i]], dp[i-1][j+a[i]]);
					else dp[i][j] = dp[i-1][j-a[i]];
				}
				else
				{
					if (j + a[i] <= 100000)
					dp[i][j] = max(dp[i-1][a[i]-j], dp[i-1][a[i]+j]);
					else dp[i][j] = dp[i-1][j-a[i]];
				}
			}
			if (j + a[i] <= 100000 && !dp[i][j+a[i]])	dp[i][j+a[i]] = dp[i-1][j];
		}
	}
	for (int j = 0; j <= 100000; j++)
	{
		if (dp[n][j])
		{
			cout << (pre[n] + j) / 2;
			return 0;
		}
	}
}
