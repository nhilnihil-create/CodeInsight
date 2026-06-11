#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define pii pair<int, int>

using namespace std;

ll const MOD = 998244353;
ll a[1000000], b[1000000], sum, q, mx, n;

int main()
{
    ios::sync_with_stdio(0);
    /*cin >> s;
    dp[0][s[0]]=1;
    for (int i=1; i<s.size(); i++)
    {
        dp[i][s[i]]=(dp[i-1]['a']+dp[i-1]['b']+dp[i-1]['c'])%MOD;
        if (s[i]=='a')
        {
            dp[i]['b']=dp[i-1]['c'];
            dp[i]['c']=dp[i-1]['b'];
        }
        if (s[i]=='b')
        {
            dp[i]['a']=dp[i-1]['c'];
            dp[i]['c']=dp[i-1]['a'];
        }
        if (s[i]=='c')
        {
            dp[i]['b']=dp[i-1]['a'];
            dp[i]['a']=dp[i-1]['b'];
        }
    }
    cout << (dp[s.size()-1]['a']+dp[s.size()-1]['b']+dp[s.size()-1]['c'])%MOD;*/
    cin >> n;
    mx = 1e10;
    for (int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i]>b[i] && b[i]<mx)
        {
            mx=b[i];
            q=b[i];
        }
        sum+=a[i];
    }
    if (mx==1e10)
        cout << 0;
    else cout << sum-q;
    return 0;
}
