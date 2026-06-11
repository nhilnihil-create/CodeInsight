#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int, int> >
#define fi first
#define se second
#define int long long
int a[5][205], dp[5][105];
signed main()
{
	int n;
	cin>>n;
	for(int i=1; i<=2; i++) for(int j=1; j<=n; j++) cin>>a[i][j];
	for(int i=1; i<=2; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j]=max(dp[i][j-1], dp[i-1][j])+a[i][j];
		}
	}
	cout<<dp[2][n];
}
