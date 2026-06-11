#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353

int main(void)
{
    fastio;

    string s;
    cin >> s;
    ll n=s.size(),i,ans=0,c=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='B')c++;
        else
        {
            ans=ans+c;
        }
    }
    cout << ans;

    return 0;
}
