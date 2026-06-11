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
double dp[3000][3000];
void solve()
{
	IN(n);
	vector<double>v;
	cout << setprecision(10);
	FOR(i, 0, n)
	{
		double in;
		cin >> in;
		v.push_back(in);
	}
	dp[0][0] = 1;
	FOR(i, 1, n + 1)	dp[i][0] =dp[i-1][0]*( 1 - v[i - 1]);
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, i + 1)
		{
			dp[i][j] = dp[i - 1][j - 1] * v[i - 1] + dp[i - 1][j] * (1 - v[i - 1]);
		}
	}
	double ans = 0;
	FOR(i, n / 2+1, n+1)
		ans += dp[n][i];
	cout << ans;
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