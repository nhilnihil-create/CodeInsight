#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
/*LCS gfg*/

void solve()
{
    ll n,w,i,j,m,z,k,h,mod = 1e9+7;
    double x,y;
    cin >> n;
    double a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    double dp[n][n+1];
    memset(dp,0.0,sizeof(dp));
    dp[0][0] = 1.0 - a[0];
    dp[0][1] = a[0];
    for(i=1;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            x = 0;
            y = 0;

            if(j>=1)
            {
                x = a[i]*dp[i-1][j-1];
                //cout << "here = " << x << "\n";
            }

            y = (1-a[i])*dp[i-1][j];

            dp[i][j] = x+y;

        }
    }


    double ans = 0.0;
    x = (n+1)/2;
    for(i=x;i<n+1;i++)
        ans += dp[n-1][i];
    cout << setprecision(10) << ans;



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
