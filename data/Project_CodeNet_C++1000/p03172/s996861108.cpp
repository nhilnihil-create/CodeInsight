#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define myPair pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define qmax priority_queue<int>
#define qmin priority_queue<int,vector<int>,greater<int>>
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

const int mxn = 1e5 + 10, mod = 1e9 + 7;
int dp[101][mxn], aux[101][mxn];
int n,k;
int a[mxn];

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	FOR(i,1,n)
		cin >> a[i];
	FOR(j,1,k)
	{
		dp[0][j] = 0;
		aux[0][j] = 1;
	}
	aux[0][0] = dp[0][0] = 1;

	FOR(i,1,n)
	{
		aux[i][0] = dp[i][0] = 1;
		FOR(j,1,k)
		{
			int count = j - min(j, a[i]);
			if(count == 0)
				dp[i][j] = aux[i - 1][j];
			else
				dp[i][j] = (aux[i - 1][j] - aux[i - 1][count - 1] + mod) % mod;
		}
		FOR(j,1,k)
			aux[i][j] = (aux[i][j - 1] + dp[i][j]) % mod;
	}
	cout << dp[n][k];

	return 0;
}
