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
    cin >> n >> k;
    ll a[n];
    for(i=0;i<n;i++)
        cin >> a[i];

    ll dp[n];
    for(i=0;i<n;i++)
        dp[i] = 1e10;
    dp[0] = 0;

    for(i=1;i<n;i++)
    {
        x = 1;
        while(i-x >= 0 && x <= k)
        {
            dp[i] = min(dp[i], dp[i-x] + abs(a[i] - a[i-x]));
            x++;
        }
    }
    /*for(i=0;i<n;i++)
        cout << dp[i] << " ";*/
    cout << dp[n-1];




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
