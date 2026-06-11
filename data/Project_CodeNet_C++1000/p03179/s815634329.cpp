#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<ll> > dp1 (n+1, vector<ll> (n+1)) , dp2(n+1, vector<ll> (n+1));
    dp1[1][1] = 1;
    for(int i =1; i<= n; i++)
        dp2[1][i] = (dp2[1][i-1] + dp1[1][i]);
    for(int i =2; i<=n; i++)
    {
        for(int j = 1; j<= i ; j++)
        {
            if(s[i-2] == '<')
                dp1[i][j] = dp2[i-1][j-1];
            else 
                dp1[i][j] = (dp2[i-1][i-1] + (MOD - dp2[i-1][j-1]))%MOD;
            dp2[i][j] = (dp2[i][j-1] + dp1[i][j])%MOD;
        }
    }
    ll ans = 0;
    for(int i = 1; i<= n;i++)
        ans = (ans + dp1[n][i])%MOD;
    cout<<ans<<"\n";
}