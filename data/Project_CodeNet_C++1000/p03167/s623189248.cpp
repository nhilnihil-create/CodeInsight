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
    ll n,w,i,j,m,x,y,z,k,h,mod = 1e9+7;
    cin >> h >> w;
    string a[h];
    for(i=0;i<h;i++)
        cin >> a[i];
    ll dp[h][w];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(i == 0 && j == 0)
                continue;
            if(a[i][j] == '#')
                dp[i][j] = 0;
            else
            {
                x = 0;
                y = 0;
                if(i-1 >= 0)
                    x = dp[i-1][j];
                if(j-1 >= 0)
                    y = dp[i][j-1];

                dp[i][j] = (x+y)%mod;
            }
        }
    }
    cout << dp[h-1][w-1]%mod;





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
