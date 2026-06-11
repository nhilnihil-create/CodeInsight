#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
	ll n,a,b,c;;
	cin >> n;
	ll dp[n+1][3];
	// ll a[n];
	cin >> a >> b >> c;
	dp[1][0]=a;
	dp[1][1]=b;
	dp[1][2]=c;
	for(ll i=2;i<=n;i++)
	{
		cin >> a >> b >> c;
		dp[i][0]=a+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=b+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=c+max(dp[i-1][0],dp[i-1][1]);
	}
	cout << max(max(dp[n][0],dp[n][1]),dp[n][2]);
}
int main()
{
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("ouput.txt","w",stdout);
	//#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}