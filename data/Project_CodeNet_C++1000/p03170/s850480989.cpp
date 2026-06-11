#include<bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define endl '\n'
#define for(i,s,n) for(int i=s;i<n;i++)
#define vii vector<int>
int t = 1, n, k;
vii v;
int dp[2][100001];
int solve(int player, int rem) {///0 for First ,1 for Second
	if (rem < 0) return player;
	int& ret = dp[player][rem];
	if (~ret) return ret;
	bool ok = 0;
	for (i, 0, n) {
		int r = solve((player + 1) % 2, rem - v[i]);
		if (r == player) ok = 1;
	}
	if (ok) return ret = player;
	else return ret = (player + 1) % 2;
}
signed main()
{
	fast;
	///cin>>t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		v = vii(n);
		for (i, 0, n) cin >> v[i];
		if (solve(0, k))
			cout << "Second\n";
		else
			cout << "First\n";
	}
}
