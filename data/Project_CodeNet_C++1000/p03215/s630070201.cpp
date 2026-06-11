#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
const ll MAXV = 1e+12;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a_values(n);
    rep(i, 0, n) cin >> a_values[i];

    vector<ll> csum(n+1, 0);
    rep(i, 0, n) csum[i+1] = csum[i] + a_values[i];

    vector<ll> values;
    rep(i, 0, n)
        rep(j, i+1, n)
            values.push_back(csum[j+1]-csum[i]);
    
    ll base = 1;
    while (base < MAXV) base <<= 1;

    while (base)
    {
        int num = 0;
        vector<ll> new_values;

        for (auto v: values)
        {
            if (base & v)
            {
                new_values.push_back(v);
                ++num;
            }
        }

        if (num >= k)
            swap(values, new_values);
        base >>= 1;
    }

    ll ans = values[0];
    for (auto v: values)
        ans &= v;

    cout << ans << endl;
    return 0;
}