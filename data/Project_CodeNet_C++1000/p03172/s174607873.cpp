/////////////////////////////////TEST CASES////////////////////////////////////
/*
*/
/////////////////////////////////////CODE//////////////////////////////////////		
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.14159265
typedef long long ll;
#define vl vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define all(a) a.begin(),a.end()
#define FR(i,a) for(auto i:a)
#define what(A) cout<<#A<<" is "<<A<<endl;
ll MAX = 100000000000;
ll MOD = 1000000007;
ll dp[100010][2];
ll sum[110];
void solve()
{
	IN(n)IN(k);
	vl v;
	FOR(i, 0, n)
	{
		IN(in);
		v.pb(in);
	}
	sum[0] = v[0];
	FOR(i, 1, n)
		sum[i] = sum[i - 1] + v[i];
	dp[0][0] = 1;
	dp[0][1] = 1;
	FOR(i, 0, n)
	{
		FOR(j, 1, k + 1)
		{
			if (sum[i] >= j)
				dp[j][1] = (dp[j - 1][1] + dp[j][0]-(j-v[i]>0?dp[j-v[i]-1][0]:0)+MOD)%MOD;
		}
		FOR(j, 1, k + 1)
		{
			//cout << dp[j][1];
			dp[j][0] = dp[j][1];
		}
		//cout << endl;
	}
	cout << dp[k][0]%MOD;
}
int main()
{
	fastio
		//freopen("input.txt", "rt", stdin);
		//freopen("output.txt", "wt", stdout);
		ll test = 1;
	//cin >> test;
	while (test--)
	{
		solve();
	}
}