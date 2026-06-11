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
    ll n,w,i,j,m,x,y,z,k;

    string s1, s2;
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    ll a[n+1][m+1];
    memset(a,0,sizeof(a));
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<m+1;j++)
        {
            if(i == 0 || j  == 0)
            {
                a[i][j] = 0;
            }
            else
            {
                char c1 = s1[i-1];
                char c2 = s2[j-1];
                if(c1 == c2)
                {
                    a[i][j] = 1 + a[i-1][j-1];
                }
                else
                {
                    a[i][j] = max(a[i-1][j],a[i][j-1]);
                }
            }
        }

    }
    i = n;
    j = m;
    string ans = "";
    while(i >= 1 && j >= 1)
    {
        x = a[i][j];
        y = a[i][j-1];
        z = a[i-1][j];
        k = a[i-1][j-1];
        if(x == k+1 && s1[i-1] == s2[j-1])
        {
            ans = s1[i-1] + ans;
            i--;
            j--;
        }
        else
        {
            if(x == y)
            {
                j--;
            }
            else
            {
                i--;
            }
        }

    }
    cout << ans;



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
