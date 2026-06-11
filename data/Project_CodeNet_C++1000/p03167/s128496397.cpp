#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void FIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int h, w;
bool a[1002][1002];
int dp[1002][1002];

int solve(int i, int j)
{
	if (i == h && j == w) // standing on the last cell
	{
		return 1;
	}
	else if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	int op1 = 0, op2 = 0;

	op1 = (a[i][j + 1] || j + 1 > w) ? 0 : solve(i, j + 1);
	op2 = (a[i + 1][j] || i + 1 > h) ? 0 : solve(i + 1, j);

	return dp[i][j] = (op1 + op2) % mod;

}

int32_t main()
{
	FIO();
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			char ch; cin >> ch;
			if (ch == '.')
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = 1;
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1) << '\n';
	return 0;
}