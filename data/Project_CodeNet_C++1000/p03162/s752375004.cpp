#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second


void solve()
{
    ll n,i,j,k,x,y,z;
    cin >> n;
    ll a[n];
    ll b[n];
    ll c[n];
    ll dp[3][n];
    for(i=0;i<n;i++)
        cin >> a[i] >> b[i] >> c[i];

    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];

    for(i=1;i<n;i++)
    {
        dp[0][i] = a[i] + max(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = b[i] + max(dp[0][i-1],dp[2][i-1]);
        dp[2][i] = c[i] + max(dp[0][i-1],dp[1][i-1]);
    }
    ll ma = 0;
    ma = max(dp[0][n-1],max(dp[1][n-1],dp[2][n-1]));
    cout << ma;




}
int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
	//cin >> t;
	while(t-- > 0)
	{
		solve();
	}

}
