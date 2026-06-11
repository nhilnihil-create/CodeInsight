#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    ll * dp = new ll[n]();

    for(int i=1;i<n;i++)
    {
        if( s[i] =='C' && s[i-1] =='A')
        {
            dp[i] = 1 + dp[i-1];
        }
        else dp[i ] = dp[i-1];
    }
    for(int i=0;i<q;i++)
    {
        ll l , r;
        cin>>l>>r;
        l--;
        r--;
        cout<<dp[r] - dp[l] <<"\n";
    }
}