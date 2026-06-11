#include<bits/stdc++.h>
//#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define endl '\n'
#define for(i,s,n) for(int i=s;i<n;i++)
#define vii vector<int>
int n, k;
int v[110];
int dp[100005][3];
int solve(int rem=k, bool player=0) {///0 for First ,1 for Second
	//if (rem < 0) return player;
	int& ret = dp[rem][player];
	if (~ret) return ret;
	ret = !player;
	for (i, 0, n) {
		if (v[i] <= rem) {
			if (solve(rem - v[i], !player) == player) {
				ret = player;
			}
		}
	}
	return ret;
}
signed main()
{
	   fast;
  
	cin >> n >> k;
	for (i, 0, n) cin >> v[i];
	memset(dp, -1, sizeof dp);
	int sol = solve();
	if (!sol) cout << "First\n";
	else cout << "Second\n";
}
