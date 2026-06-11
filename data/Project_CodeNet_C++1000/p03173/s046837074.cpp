#include<bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define endl '\n'
//#define for(i,s,n) for(int i=s;i<n;i++) 
#define vii vector<int>
int t = 1, n, OO = 1e14;
vii v, cum;
int dp[402][402];
int solve(int i, int j) {
	if (i + 1 == j) return v[i] + v[j];
	if (i == j) return 0;
	int& ret = dp[i][j];
	if (~ret) return ret;
	ret = OO;
	for (int k = i; k < j; k++) {
		ret = min(ret, (cum[j] - cum[i - 1]) + solve(i, k) + solve(k+1, j));
	}
	return ret;
}
signed main()
{
	fast;
	
	//cin>>t;
	while (t--)
	{
		cin >> n;
		v = vii(n+1);
		for (int i = 1; i <= n; i++) cin >> v[i];
		cum = vii(n + 1);
		for (int i = 1; i <= n; i++) cum[i] = cum[i - 1] + v[i];
		memset(dp, -1, sizeof dp);
		cout<<solve(1,n)<<endl;
	}
}