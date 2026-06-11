#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s,t,p;
    cin>>s;
    cin>>t;
    ll m = s.length();
    ll n = t.length();
    ll dp[m+1][n+1];
    for(ll i=0; i<=m; i++)
    {
        dp[i][0] = 0;
    }
    for(ll i=0; i<=n; i++)
    {
        dp[0][i] = 0;
    }
    
    for(ll i=1; i<=m; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    while(m>0 && n>0)
    {
        if(s[m-1] == t[n-1])
        {
            p.push_back(s[m-1]);
            m--;
            n--;
        }
        else if(dp[m-1][n] > dp[m][n-1])
        {
            m--;
        }
        else
        {
            n--;
        }
    }
    if(p.length()>0)
    {
       reverse(p.begin(),p.end());
        cout<<p; 
    }
    else
    {
        cout<<" ";
    }
    return 0;
}