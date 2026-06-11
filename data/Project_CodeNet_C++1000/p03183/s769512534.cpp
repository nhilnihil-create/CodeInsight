#include <bits/stdc++.h>
using namespace std;
#define int			long long
#define ld			long double
#define uint 		unsigned long long

const int mod = 1e9 + 7;

struct box
{
	int weight;
	int strength;
	int value;
};

bool cmp(box a, box b)
{
	return ((a.strength + a.weight) > (b.strength + b.weight));
}

void solve()
{
	int n; cin >> n;
	box a[n];
	for(int i=0; i<n; i++)
	{
		cin >> a[i].weight >> a[i].strength >> a[i].value;
	}	
	sort(a, a + n, cmp);
	// dp[i][j] -> Max value for first I boxes and J units more weight can be carried by it
	const int mx = 2e4+2;
	int dp[n+1][mx];
	for(int i=0; i<n+1; i++) for(int j=0; j<mx; j++) dp[i][j] = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<mx; j++)
		{
			 dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			 if(j >= a[i].weight)
			 {
				 dp[i+1][min(j - a[i].weight, a[i].strength)] = max(dp[i+1][min(j - a[i].weight, a[i].strength)], dp[i][j] + a[i].value);
			 }
		}
	}
	int ans = 0;
	for(int i=0; i<n+1; i++) for(int j=0; j<mx; j++) ans = max(ans, dp[i][j]);
	cout << ans << endl;
}

signed main()
{	
	int T = 1; 
	// cin >> T;
	while(T--)
		solve();
	return 0;
}



