#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> ac(n, 0), cc(n, 0), ncl(n, 0), ncr(n, 0);
    ac[0] = (s[0] == 'A');
    cc[n - 1] = (s[n - 1] == 'C');
    ncl[0] = (s[0] == '?');
    ncr[n - 1] = (s[n - 1] == '?');

    for(int i = 1; i < n; i++)
    {
        ac[i] = ac[i - 1];
        ac[i] += (int)(s[i] == 'A');
        ncl[i] = ncl[i - 1];
        ncl[i] += (int)(s[i] == '?');
    }

    for(int i = (n - 2); i >= 0; i--)
    {
        cc[i] = cc[i + 1];
        cc[i] += (int)(s[i] == 'C');
        ncr[i] = ncr[i + 1];
        ncr[i] += (int)(s[i] == '?');
    }   

    vector <ll> p3(n + 1, 1);

    for(int i = 1; i <= n; i++)
        p3[i] = (p3[i - 1] * 3) % mod;

    ll ans = 0;

    for(int i = 1; i < (n - 1); i++)
    {
        if(s[i] == 'A')
            continue;
            
        if(s[i] == 'C')
            continue;

        ll lans = 0, nl = ncl[i - 1], nr = ncr[i + 1], rans = 0;
        lans = (p3[nl] * ac[i - 1]) % mod;

        if(nl)
            lans = (lans + (nl * p3[nl - 1]) % mod) % mod;

        rans = (p3[nr] * cc[i + 1]) % mod;

        if(nr)
            rans = (rans + (nr * p3[nr - 1])% mod) % mod;

        ans = (ans + (lans * rans)) % mod;
    }   

    ans = (ans + mod) % mod;
    cout << ans <<"\n";
    return 0;
}
