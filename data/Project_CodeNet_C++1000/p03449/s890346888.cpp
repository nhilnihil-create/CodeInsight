#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define pb push_back
#define ll long long
#define fi first
#define se second
#define maxn 101

const int mod = 1e9+7 ;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int dp[3][maxn];

signed main()
{
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	fastio;
	int n;	cin >> n;
	int a[3][n+1];
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
		}
	}
	cout << dp[2][n];
}


