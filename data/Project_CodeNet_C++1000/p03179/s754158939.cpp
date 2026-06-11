#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpli vector<pair<long long, int>>
#define vs vector<string>
#define deb(x) cout << x << endl;
#define all(x) x.begin(), x.end()
const int MOD = 1e9+7;

void add(int &a,int b)
{
    a = a+b;
    if(a>MOD)
        a-=MOD;
}

void solve()
{
    //dp[i][j] = number of length i string with i-1 inequalities satisfied with number at index i = j.
    int n;
    string s;
    cin>>n>>s;
    vvi dp(n+1,vi(n+1,0));
    dp[1][1] = 1;
    int L,R;
    for(int len=2;len<=n;len++)
    {
        vi pref(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pref[i] = (pref[i-1]+dp[len-1][i])%MOD;
        }
        for(int numberAtEnd = 1;numberAtEnd<=len;numberAtEnd++)
        {
            if(s[len-2] == '<')
            {
                L=1;
                R=numberAtEnd-1;
            }
            else   // s[len-2] == '>'
            {
                L=numberAtEnd;
                R=len-1;
            }
            if(L<=R)
            {
                add(dp[len][numberAtEnd],(pref[R]-pref[L-1]+MOD)%MOD);
            }
        }
    }
    int  ans = 0;
    for(int i=1;i<=n;i++)
    {
        add(ans,dp[n][i]);
    }
    cout<<ans;
}

int main()
{
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}