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
    for(i=0;i<n;i++)
        cin >> a[i];

    ll dp[n];
    dp[0] = 0;
    for(i=1;i<n;i++)
    {
        if(i-2 >= 0)
        {
            x = dp[i-1] + abs(a[i] - a[i-1]);
            y = dp[i-2] + abs(a[i] - a[i-2]);
            dp[i] = min(x,y);
        }
        else
        {
            dp[i] = dp[i-1] + abs(a[i] - a[i-1]);
        }
    }
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
