#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> sh(n, vector<ll>(10));
    vector<vector<ll>> pro(n, vector<ll>(11));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 10; j++)
        {
            cin >> sh[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 11; j++)
        {
            cin >> pro[i][j];
        }
    }
    ll ans = -10000000000000;
    for (ll bit = 0; bit < (1 << 10); bit++)
    {
        ll sum = 0;
        set<ll> st;
        for (ll i = 0; i < 10; i++)
        {
            if (bit & (1 << i))
                st.insert(i);
        }
        if(st.size() == 0)
        continue;
        vector<ll> open_or_not(n, 0);
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 10; j++)
            {
                if (sh[i][j] == 1 && st.count(j))
                    open_or_not[i]++;
            }
            if (open_or_not[i] == 0)
                cnt++;
        }
       
            for (ll i = 0; i < n; i++)
            {
                sum += pro[i][open_or_not[i]];
            }
            ans = max(ans, sum);
    }
    cout << ans << endl;
}
